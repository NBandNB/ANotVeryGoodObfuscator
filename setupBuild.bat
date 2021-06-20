cd C:\

git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat && .\vcpkg.exe install gtkmm:x64-windows &&.\vcpkg.exe install gtkmm:x86-windows && echo "Your build enviroment is now set up"
