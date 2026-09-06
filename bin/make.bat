SolutionGenerator.exe -bp -make

copy /Y "..\lib\SDL3\lib\x64\*.dll" "..\ide\IMGUI\"
copy /Y "..\lib\SDL3\lib\x64\*.dll" "..\ide\Test\"

PAUSE