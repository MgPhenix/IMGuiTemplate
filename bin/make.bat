SolutionGenerator.exe -bp -make

copy /Y "..\lib\SDL3\lib\x64\*.dll" "..\ide\ImGUI\"
copy /Y "..\lib\SDL3\lib\x64\*.dll" "..\ide\Test\"
copy /Y "..\lib\SDL3\lib\x64\*.dll" "..\ide\ImGuiWrapper\"

PAUSE