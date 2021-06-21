@echo off

IF NOT EXIST %2%\alreadyCopied.txt (
	echo > %2%\alreadyCopied.txt
	IF "%4%"=="Debug" ( 
		copy C:\vcpkg\installed\%1-windows\debug\bin\* %2%
		echo "Copied .dlls from debug\bin\"
	) ELSE (
		copy C:\vcpkg\installed\%1-windows\bin\* %2%
		echo "Copied .dlls from \bin\"
	)
	echo "Copied .dll files"
	if not exist %3% (
		mkdir %3%
		echo "made new dir"
	)
	copy C:\vcpkg\installed\%1-windows\share\glib-2.0\schemas\* %3%
	echo "copied schemas" 
) ELSE (
	echo "Not re-copying"
)