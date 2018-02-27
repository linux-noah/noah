# Noah [![Build Status](http://noah-ci.idylls.jp/job/noah/badge/icon)](http://noah-ci.idylls.jp/job/noah/)

Noah is a Darwin subsystem for Linux, or "Bash on Ubuntu on Mac OS X". Noah is implemented as a hypervisor that traps linux system calls and translates them into Darwin's system calls. Noah also has an interpreter of ELF files so that binary executables of Linux run directly and flawlessly without any modifications.

<img src="https://github.com/linux-noah/noah/blob/master/images/screenshot.png" width="600">

## Quick Start

Noah is installed via homebrew. On the first run, noah automatically downloads and installs a comprehensive linux environment in your home directory (by default, ubuntu 16.04 is installed in `~/.noah/tree`).
macOS Sierra or higher is required.

```console
$ brew install linux-noah/noah/noah
$ noah
```

## Hacking

See [HACKING.md](HACKING.md).

## LICENSE

Dual MITL/GPL, for all files without explicit notaiton.
