set render=src\engine\render\render.c src\engine\render\render_init.c src\engine\render\render_util.c
set io=src\engine\io\io.c
set config=src\engine\config\config.c
set input=src\engine\input\input.c
set time=src\engine\time\time.c
set files=src\glad.c src\main.c src\engine\global.c %render% %io% %config% %input% %time%
set libs=E:\Development\Blueberry\lib\SDL2main.lib E:\Development\Blueberry\lib\SDL2.lib

CL /Zi /I E:\Development\Blueberry\include %files% /link %libs% /OUT:blueberry.exe