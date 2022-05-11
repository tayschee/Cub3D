# Cub3D
![42](https://img.shields.io/static/v1?label=&labelColor=000000e&logo=42&message=project&color=000000&style=flate)
![Stars](https://img.shields.io/github/stars/tayschee/Cub3D?style=social)

## Summary
- [About The Project](#about-the-project)
- [Cub File](#cub-file)
## About The Project
[Cub3D](https://cdn.intra.42.fr/pdf/pdf/47636/fr.subject.pdf) is project of 42Paris to learn [raycasting](https://fr.wikipedia.org/wiki/Raycasting#:~:text=Le%20raycasting%20est%20une%20technique,par%20une%20carte%20graphique%20d%C3%A9di%C3%A9e.). \
It consist to reproduce famous game [Wolfenstein 3D](http://wolf3d.atw.hu/) entirely in C.

![PONG GAME PAGE](image.png)

### Built With
![C](https://img.shields.io/static/v1?label=&labelColor=30485e&logo=C&message=test&color=3fb985&style=for-the-badge)

### Installation
Clone and move into clone directory:
```
git clone git@github.com:tbigot/Cub3D.git Cub3D
cd Cub3D
make
```
### Run
Run Cub3D with path to .cub file in parameter like this:
```
./cub3d ressources/map/demo.cub
```
You can do your own file.cub to that follow the rules.

### Delete
```
make fclean
```

## Cub file

### Rules
- Extension name must be .cub
- Start with Header
- After Header there is a map
- header and map must be separated by one empty line
#### Header Rules
- Each line start by letter or a group of letter then take a parameter
- The first line is always a dimension line
- The other line can be put in any order and describe sprite, walls texture, and color of ground and ceiling
##### Dimension Line
- give the dimension of window game in pixel: "R WIDHT HEIGHT"
- WIDHT and HEIGHT must be superior to 60
##### Wall Line
- Wall have different texture depends on their orientation: North, South, West, East
- each texture must be .xml file
- You must describe all of them in any order only one time
- For north texture : "NO path/to/wall/north/texture/file"
- For south texture : "SO path/to/wall/south/texture/file"
- For west texture : "EA path/to/wall/west/texture/file"
- For east texture : "WE path/to/wall/east/texture/file"
- 
##### Sprite Line
- Sprite line take the following form: "S path/to/sprite/file"
- You can have only one sprite line by .cub file
- Sprite must be a xml file where black color will be replace by transparency

##### Color Line
- Floor and ceiling are describe with RGB color
- You must describe both of them only one time
- For Floor : "F RED,GREEN,BLUE"
- For Ceiling: "C RED,GREEN,BLUE"


#### Map Rules
- a map can be construct only with those 6 characters :
  - 1 for a wall
  - 2 for a sprite
  - 0 for an empty space surronded by wall 
  - N for player who look at the north
  - S for player who look at the south
  - W for player who look at the west
  - E for player who look at the east
  - " "(space) for an empty space
- each map must contain exactly one player
- player must be surrounded by wall

#### Exemple

```
R 600 500
NO ./resources/texture/greystone.xpm
SO ./resources/texture/greystone.xpm
WE ./resources/texture/greystone.xpm
EA ./resources/texture/greystone.xpm
S ./resources/sprite/pillar.xpm
F 100,100,100
C 50,50,50

  1111111111111111 1111       1111 1111111111      111111111111 11111111111
  1200000000000001 1001       1001 1000000001      100000000001 100000000001
  1200200000002001 1001       1001 1000000001      111111111001 1001111110001
  1000011111111111 1001       1001 1000000001              1001 1001     1001
  100001           1001       1001 1000000001         111111001 1001     1001
  10N001           1001       1001 10111111111111     100000001 1001     1001
  100001           1001       1001 100000000000001    111111001 1001     1001
  1002011111111111 1001       1001 100000000000001         1001 1001     1001      
  1000000200000001 100111111111001 100000000000001 111111111001 1001111110001
  1020000000000001 100000000000001 100000000000001 100000000001 100000000001
  1111111111111111 111111111111111 111111111111111 111111111111 11111111111
```
