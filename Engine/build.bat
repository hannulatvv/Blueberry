set files=src\glad.c src\main.c
set libs=E:\Development\Blueberry\lib\SDL2main.lib E:\Development\Blueberry\lib\SDL2.lib E:\Development\Blueberry\lib\freetype.lib

CL /Zi /I E:\Development\Blueberry\include %files% /link %libs% /OUT:blueberry.exe