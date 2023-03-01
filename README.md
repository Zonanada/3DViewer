## Introduction

В данном проекте реализованна на языке программирования Си программа для просмотра 3D моделей в каркасном виде (3D Viewer). Сами модели необходимо загружать из файлов формата .obj и иметь возможность просматривать их на экране с возможностью вращения, масштабирования и перемещения.

### Для запуска требуется:

- make
- cmake
- gcc
- qt6-base-dev
- libqt6charts6-dev
- build-essential 
- libgl1-mesa-dev

```
sudo apt install -y git
sudo apt install -y cmake
sudo apt install -y gcc
sudo apt install -y qt6-base-dev
sudo apt install -y libqt6charts6-dev
sudo apt install -y build-essential libgl1-mesa-dev
```

### Build:
```
cd src && make install