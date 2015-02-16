# bfos - Brandon Frie OS
My operating system


## Project Organization
The source code for this project is organized in to the following structure:

- src
  - boot
  - kernel
  - lib
- docs
  - api
  - user
  
### src Folder
The src folder is the root development folder which contains all files required to build the OS binary.

#### boot Folder
This folder contains all the files required to bootstrap the operating system.

#### kernel Folder
This folder contains all the low-level files which constitute the kernel of the operating system.

#### lib Folder
This folder contains all of the OS-wide library files.  It may be split into a C library and a kernel library at some point.

### docs Folder
This is the root folder for all documentation for the project.  It will include any system API documentation as well as user manuals, etc.

## Build Environment
I'm using Xubuntu as my development operating system for now.  Eventually, development should transition into BFOS.  You'll need to setup a cross-compiler (see instructions at: http://wiki.osdev.org/GCC_Cross-Compiler).  The components I used to build my compiler are:
- binutils 2.25
- gcc 4.9.2
  - cloog 0.18.1
  - gmp 4.3.2
  - isl 0.12.2
  - mpc 0.8.1
  - mpfr 2.4.2
 
The GCC infrastructure components can be downloaded from ftp://gcc.gnu.org/pub/gcc/infrastructure.