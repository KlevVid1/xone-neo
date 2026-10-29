# xone-neo

<p align="center">
    <img src="logo.svg" alt="xone-neo Logo" width="200">
</p>

<p align="center">
    <b>Современный драйвер ядра Linux для аксессуаров Xbox One и Xbox Series X|S с синтезом отдачи на курках (Impulse Triggers)</b>
</p>

<p align="center">
    <a href="README.md"><b>English</b></a> | <b>Русский</b>
</p>

<p align="center">
    <a href="#features">Возможности</a> •
    <a href="#demo">Демо</a> •
    <a href="#configuration">Настройка</a> •
    <a href="#installation">Установка</a> •
    <a href="#reloading">Перезапуск</a> •
    <a href="#uninstallation">Удаление</a> •
    <a href="#credits">Благодарности</a>
</p>

---

**`xone-neo`** — это улучшенный форк драйвера [`xone`](https://github.com/dlundqvist/xone) (авторы *medusalix* и *dlundqvist*). В проект добавлен **синтез вибрации импульсных курков** (по аналогии с концепцией [`xpadneo`](https://github.com/atar-axis/xpadneo)), что даёт тактильную отдачу на левом и правом курках (LT/RT) в играх под Linux и Proton/Wine, которые имеют обычную вибрацию, но лишены нативной поддержки вибрации триггеров.

> <sub>**Почему это отдельный форк, а не Pull Request в апстрим xone?**<br>
> Разработчики оригинального `xone` придерживаются строгой философии «чистой трансляции протокола» (строгое соответствие 1-к-1 между Microsoft GIP и подсистемой input ядра без программных эвристик). Позиция авторов апстрима заключается в том, что поддержка импульсных курков в идеале должна быть реализована нативно на уровне спецификации ядра `evdev` и библиотек ввода (SDL, Wine), а не эмулироваться на стороне драйвера. Форк `xone-neo` создан как практичное решение для игроков, желающих получить живую тактильную отдачу в играх прямо сейчас, не дожидаясь многолетних согласований API.</sub>

---

<h2 id="demo">🎬 Демонстрация работы</h2>

<p align="center">
    <video src="https://github.com/user-attachments/assets/37c8b137-1169-4dec-89a6-93eed2c907fe" controls width="80%"></video><br>
    <sub>🔊 <b>Смотрите со звуком, чтобы услышать работу вибромоторчиков курков!</b></sub>
</p>

---

<h2 id="features">✨ Возможности</h2>

- **🎮 Все возможности оригинального `xone`**:
  - Полная поддержка беспроводного подключения через официальный USB-адаптер (Xbox Wireless Dongle).
  - Поддержка проводного подключения по USB.
  - Нативная работа по протоколу Game Input Protocol (GIP).
  - Звук через 3.5 мм аудиоразъём геймпада (воспроизведение и запись через ALSA).
  - Отображение уровня заряда аккумулятора (интеграция с UPower).
  - Поддержка Xbox One Chatpad, лепестков Elite-геймпадов и совместимых геймпадов сторонних производителей.

- **⚡ Синтез вибрации курков (эмуляция Impulse Triggers)**:
  - **Масштабирование по силе нажатия**: Вибрация моторчиков курков вычисляется пропорционально тому, насколько глубоко нажат курок ($\text{основная вибрация} \times \text{глубина нажатия}$).
  - **Адаптивный интервал обновления**: Пока вибрация в игре продолжается, сила курков плавно обновляется каждые **0.5 секунды** (настраивается), предотвращая перегрузку беспроводного канала и сброс моторчиков.
  - **Мгновенное выключение при отпускании**: Как только вы отпускаете курок, моторчик на нём выключается мгновенно, не дожидаясь таймера.
  - **Автономный режим**: Позволяет включать виброотклик курков при нажатии даже на рабочем столе или в играх без виброэффектов.
  - **Полная мощность основных моторов**: Главные вибромоторы в рукоятках геймпада остаются на 100% мощности и не ограничиваются.

---

<h2 id="configuration">⚙️ Настройка и параметры модуля</h2>

Все параметры можно изменять на лету через `sysfs` без перезагрузки или задать перманентно через `/etc/modprobe.d/`.

### Доступные параметры

| Параметр | Тип | По умолчанию | Описание |
|---|---|---|---|
| `trigger_rumble_mode` | byte | `0` | `0`: Вибрация курков пропорционально нажатию во время вибро в игре (по умолчанию)<br>`1`: Автономный режим (курки вибрируют при нажатии всегда)<br>`2`: Полностью отключить вибрацию курков |
| `trigger_rumble_interval` | ushort | `500` | Интервал обновления вибрации курков в миллисекундах во время непрерывного вибро (по умолчанию: `500` мс / 0.5 сек). Значение `0` — мгновенное обновление. |
| `trigger_rumble_attenuation` | byte | `0` | Процент ослабления моторчиков курков от `0` (полная сила) до `100` (выключены). |

### Настройка на лету (через sysfs)

Параметры можно менять в реальном времени прямо во время игры:

```bash
# Включить автономный режим (курки жужжат при нажатии везде)
echo 1 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_mode

# Вернуться в стандартный игровой режим
echo 0 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_mode

# Изменить интервал обновления на 250 мс (0.25 сек)
echo 250 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_interval

# Ослабить вибрацию курков на 30%
echo 30 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_attenuation
```

### Постоянная настройка (после перезагрузки)

Создайте файл конфигурации `/etc/modprobe.d/xone-neo.conf`:

```ini
# /etc/modprobe.d/xone-neo.conf
options xone_gip_gamepad trigger_rumble_mode=0 trigger_rumble_interval=500 trigger_rumble_attenuation=0
```

---

<h2 id="installation">🚀 Установка</h2>

### 1. Подготовка зависимостей

Убедитесь, что у вас установлены DKMS и заголовки текущего ядра Linux:

* **Arch Linux / Manjaro**:
  ```bash
  sudo pacman -S dkms linux-headers git
  # (или linux-lts-headers, linux-zen-headers, linux-tkg-bore-headers под ваше ядро)
  ```
* **Ubuntu / Debian / Pop!_OS**:
  ```bash
  sudo apt install dkms linux-headers-generic git curl libarchive-tools
  ```
* **Fedora**:
  ```bash
  sudo dnf install dkms kernel-devel kernel-headers git
  ```

### 2. Установка xone-neo

Склонируйте репозиторий и запустите скрипт установки:

```bash
git clone https://github.com/KlevVid1/xone-neo.git
cd xone-neo
sudo ./install.sh
```

### 3. Прошивка беспроводного адаптера (только для донгла)

Если вы используете официальный беспроводной USB-адаптер Microsoft, установите для него прошивку:

* **Arch Linux (AUR)**:
  ```bash
  yay -S xone-dongle-firmware
  ```
* **Другие дистрибутивы**:
  ```bash
  sudo ./install/firmware.sh
  ```
*(При подключении геймпада по обычному проводу USB прошивка не требуется).*

---

<h2 id="reloading">🔄 Перезапуск драйвера без перезагрузки системы</h2>

Чтобы применить изменения или перезапустить драйвер:

```bash
sudo modprobe -r xone_gip_gamepad xone_gip xone_dongle xone_wired
sudo modprobe xone_dongle
sudo modprobe xone_gip_gamepad
```
*(Либо просто отключите и снова вставьте USB-адаптер или кабель геймпада).*

---

<h2 id="uninstallation">🗑️ Удаление</h2>

Для полного удаления `xone-neo` из системы:

```bash
cd xone-neo
sudo ./uninstall.sh
```

---

<h2 id="credits">🤝 Благодарности</h2>

- **[medusalix](https://github.com/medusalix)** — за создание оригинального драйвера `xone` и реверс-инжиниринг протокола GIP.
- **[dlundqvist](https://github.com/dlundqvist)** — за поддержку и обновление кодовой базы `xone`.
- **[atar-axis и команда xpadneo](https://github.com/atar-axis/xpadneo)** — за идею синтеза вибрации курков на основе силы нажатия.
- **[KlevVid](https://github.com/KlevVid1)** — за разработку `xone-neo` и интеграцию синтеза курков.

---

## 📄 Лицензия

Проект распространяется под свободной лицензией **GNU General Public License v2.0 or later (GPL-2.0-or-later)** — подробнее см. в файле [LICENSE](LICENSE).
