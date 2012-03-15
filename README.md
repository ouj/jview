JVIEW
========
This image viewer is the by-product of my computer graphics research. 

I mainly use this image view to display PFM image. PFM is a image format for HDR image. 
[PFM is a uncompressed image format](http://netpbm.sourceforge.net/doc/pfm.html). It basically serialize all the binary data into a file. In my research, I frequently need to use or generate HDR images. After trying EXR, which is the industrial standard for HDR image format, I decide to use binary PFM because it is simple to parse and do not need any external library. However this viewer also support other HDR image formats, include EXR, TGA. 


Dependency
-------------
To build the project, you need to have Xcode installed. You also need to have the following packages installed in the system:

1. CMAKE
2. Qt4

If you have homebrew installed, you can just install the package above using homebrew command:

```
brew install cmake
```

and

```
brew install qt
```

The CMakeList.txt is configured assuming that homebrew is installed at `/usr/local/`.

Build
--------------
Run the `cmake-xcode.sh` to create a Xcode project, or run `cmake-mk.sh` to create a makefile. Use Xcode or `make` to build the project.