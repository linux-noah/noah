# Noah [![Build Status](http://noah-ci.idylls.jp/job/noah/badge/icon)](http://noah-ci.idylls.jp/job/noah/)

Noah is a Darwin subsystem for Linux, or "Bash on Ubuntu on Mac OS X". Noah is implemented as a hypervisor that traps linux system calls and translates them into Darwin's system calls. Noah also has an interpreter of ELF files so that binary executables of Linux run directly and flawlessly without any modifications.

## Quick Start

Noah is installed via homebrew. On the first run, noah automatically downloads and installs a comprehensive linux environment in your home directory (by default, ubuntu 16.04 is installed in `~/.noah/tree`).

    $ brew tap linux-noah/noah
    $ brew install noah
    $ noah

## LICENSE

We are seeking for ways to keep our development continuous. To protect our rights until then, we as of now license our product under CC-NC-ND, which is stricter than usual software licenses found on github. If you are willing to support us, please get in touch with us via e-mail.

<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/3.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/3.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/3.0/">Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License</a>.
