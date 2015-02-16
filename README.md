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