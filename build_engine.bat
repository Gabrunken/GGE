gcc .\src\*.c ^
-Llib -L..\Libraries\SDL3-3.2.18\x86_64-w64-mingw32\lib -lSDL3 ^
-Iinclude -I..\Libraries\SDL3-3.2.18\x86_64-w64-mingw32\include ^
-o .\bin\GGE -mwindows