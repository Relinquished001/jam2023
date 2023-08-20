# How to build this project

Get a pre-built executable of the libdragon docker container from here [LibDragonCLI](https://github.com/anacierdem/libdragon-docker)
Initilialize the container as specified in the documentation
```
libdragon init
```

Switch to the unstable branch to get the mksprite tool
```
git -C ~/libdragon checkout unstable
libdragon install
```

Use mksprite to generate the sprites
```
libdragon exec mksprite <filename.png>
```

Use the make command to build the ROM
```
libdragon make
```
