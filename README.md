# xone-neo

<p align="center">
    <img src="logo.svg" alt="xone-neo Logo" width="200">
</p>

<p align="center">
    <b>Modern Linux kernel driver for Xbox One and Xbox Series X|S accessories with Trigger Rumble Synthesis (Impulse Triggers)</b>
</p>

---

**`xone-neo`** is an enhanced fork of the [`xone`](https://github.com/dlundqvist/xone) driver by *medusalix* and *dlundqvist*. It introduces **Impulse Trigger Rumble Synthesis** (inspired by [`xpadneo`](https://github.com/atar-axis/xpadneo)), enabling tactile feedback on the left and right triggers (LT/RT) in all Linux and Proton/Wine games, even those that lack native impulse trigger support.

---

## ✨ Features

- **🎮 All original `xone` capabilities**:
  - Full wireless support via the official Xbox Wireless USB Adapter (dongle).
  - Wired connection support via USB.
  - Native Game Input Protocol (GIP) handling.
  - Headset audio jack playback and capture via ALSA.
  - Battery reporting integrated with UPower.
  - Xbox One Chatpad, Elite paddles, and third-party peripherals support.

- **⚡ Trigger Rumble Synthesis (Impulse Triggers Emulation)**:
  - **Dynamic Pressure Scaling**: Synthesizes vibration on the independent trigger motors proportional to how far you pull the trigger ($\text{main rumble} \times \text{trigger pressure}$).
  - **Intelligent Cadence**: While rumble continues, trigger vibration smoothly updates every **0.5 seconds** (configurable) to prevent controller firmware packet flooding.
  - **Immediate Release Response**: The moment you release a trigger, vibration on that trigger cuts off instantly without waiting for any interval timer.
  - **Standalone Mode**: Allows testing or using trigger rumble haptics on actuation even without in-game rumble effects.
  - **Full Power Main Rumble**: Main grip rumble motors remain 100% unconstrained and full-strength.

---

## ⚙️ Configuration & Module Parameters

All parameters can be tuned in real-time via `sysfs` or configured permanently via `/etc/modprobe.d/`.

### Available Parameters

| Parameter | Type | Default | Description |
|---|---|---|---|
| `trigger_rumble_mode` | byte | `0` | `0`: Pressure-based trigger rumble during game rumble (default)<br>`1`: Standalone mode (vibrates on press even without game rumble)<br>`2`: Disable trigger rumble entirely |
| `trigger_rumble_interval` | ushort | `500` | Re-evaluation interval in milliseconds while rumble continues (default: `500` ms / 0.5s). Set to `0` for real-time. |
| `trigger_rumble_attenuation` | byte | `0` | Attenuation percentage for trigger motors from `0` (full strength) to `100` (silenced). |

### Runtime Configuration (via sysfs)

You can adjust settings on the fly without rebooting or reloading the driver:

```bash
# Switch to standalone test mode (vibrates on trigger pull anywhere)
echo 1 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_mode

# Switch back to game-synchronized mode
echo 0 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_mode

# Change update interval to 250 ms (0.25 sec)
echo 250 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_interval

# Reduce trigger rumble intensity by 30%
echo 30 | sudo tee /sys/module/xone_gip_gamepad/parameters/trigger_rumble_attenuation
```

### Permanent Configuration

To make your settings persistent across reboots, create a file at `/etc/modprobe.d/xone-neo.conf`:

```ini
# /etc/modprobe.d/xone-neo.conf
options xone_gip_gamepad trigger_rumble_mode=0 trigger_rumble_interval=500 trigger_rumble_attenuation=0
```

---

## 🚀 Installation

### 1. Prerequisites

Make sure you have DKMS and your kernel headers installed:

* **Arch Linux / Manjaro**:
  ```bash
  sudo pacman -S dkms linux-headers git
  # (or linux-lts-headers, linux-zen-headers, linux-tkg-bore-headers depending on your kernel)
  ```
* **Ubuntu / Debian / Pop!_OS**:
  ```bash
  sudo apt install dkms linux-headers-generic git curl libarchive-tools
  ```
* **Fedora**:
  ```bash
  sudo dnf install dkms kernel-devel kernel-headers git
  ```

### 2. Install xone-neo

Clone the repository and run the installer:

```bash
git clone https://github.com/KlevVid1/xone-neo.git
cd xone-neo
sudo ./install.sh
```

### 3. Dongle Firmware (Wireless Only)

If you use the official Xbox Wireless USB Dongle, install its proprietary firmware:

* **Arch Linux (AUR)**:
  ```bash
  yay -S xone-dongle-firmware
  ```
* **Other Distributions**:
  ```bash
  sudo ./install/firmware.sh
  ```
*(Wired USB connections do not require any firmware).*

---

## 🔄 Updating & Reloading

To reload the driver without rebooting your computer:

```bash
sudo modprobe -r xone_gip_gamepad xone_gip xone_dongle xone_wired
sudo modprobe xone_dongle
sudo modprobe xone_gip_gamepad
```
*(Or simply disconnect and reconnect the wireless adapter / USB cable).*

---

## 🗑️ Uninstallation

To remove `xone-neo` completely:

```bash
cd xone-neo
sudo ./uninstall.sh
```

---

## 🤝 Credits & Acknowledgements

- **[medusalix](https://github.com/medusalix)** for creating the revolutionary `xone` driver and reverse-engineering the GIP protocol.
- **[dlundqvist](https://github.com/dlundqvist)** for ongoing maintenance and modernization of `xone`.
- **[atar-axis & the xpadneo team](https://github.com/atar-axis/xpadneo)** for pioneering the trigger rumble pressure synthesis concept for Xbox gamepads on Linux.
- **[KlevVid](https://github.com/KlevVid1)** for `xone-neo` integration and interval-based synthesis.

---

## 📄 License

This project is licensed under the **GNU General Public License v2.0 or later (GPL-2.0-or-later)** - see the [LICENSE](LICENSE) file for details.
