# numlock
switch numlock capslock and scrolllock on/off for windows

## Release
[![Latest Release](https://img.shields.io/github/release/myfreeer/numlock.svg)](https://github.com/myfreeer/numlock/releases/latest)
[![Download](https://img.shields.io/github/downloads/myfreeer/numlock/total.svg)](https://github.com/myfreeer/numlock/releases)

## Usage
### File name
* file name contains `num` such as `numlock` affects `Num Lock` status
* file name contains `caps` or `capital` such as `capslock` affects `Caps Lock` status
* file name contains `scrl` or `scroll` such as `scroll-lock` affects `Scroll Lock` status

### Arguments
* run directly **without** any argument (for example simply double-click it) toggles status affected by file name on
* run **with** any argument toggles status affected by file name off

### Examples
* change file name to `numlock.exe` and double-click it turns `Num Lock` on
* change file name to `numlock.exe` and run it as `numlock 1` in a shell turns `Num Lock` off
* change file name to `capslock.exe` and double-click it turns `Caps Lock` on

## Build
[Releases](https://github.com/myfreeer/numlock/releases) are built with [tcc](https://bellard.org/tcc/) using `tcc numlock.c`,
it can also be built with other compliers such as gcc.
