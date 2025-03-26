# OpenGL Template for Linux & windows
![OpenGL logo from [wikipedia](https://en.m.wikipedia.org/wiki/File:OpenGL_logo.svg)](.images/OpenGL_logo.svg)
***
## Installation
In order to work with this template you will need certain dependencies and also a proper IDE, this template it's made with VScode and JetBrains CLion in mind, so please use one of them.
 - [VScode](https://code.visualstudio.com/) (for VScode you will need the [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) and [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extensions)
 - [CLion](https://www.jetbrains.com/clion/)

Once you have installed one of the IDE's above you will also need the template dependencies.
### Windows
- [MinGW](https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites)
- [CMake](https://cmake.org/download/)
- [Ninja](https://github.com/ninja-build/ninja/releases) (you can also install it by using `winget install Ninja-build.Ninja`)
### Linux
- gcc & g++ Compilers (they are usually preinstalled)
- cmake
- ninja
- glfw
- glut
- glew

## Usage
Clone the repository 
```bash
git clone https://github.com/Engel-167/OpenGL-Template-with-Clion-VScode-and-CMake.git
```
Then open it with VScode or CLion  
<p>
  <img src=".images/VScode-logo.svg" alt="VScode Logo" width="150" style="display: inline-block; margin-right: 50px;"/>
  <img src=".images/Empty.png" width="60" alt=""/> <!-- Spacer -->
  <img src=".images/Clion-logo.svg" alt="CLion Logo" width="150" style="display: inline-block;"/>
</p>


But if you are on windows you will have to specify your gcc and g++ compilers path inside the `CMakeLists.txt` File.  

**Don't Forget the double slashes** `\\`  

![Compilers-path-screenshot](.images/compilers-path.png)  
And select the `clion-debug` preset

**Visual Studio Code**

![Preset-selection](.images/Preset-selection.png)

**JetBrains CLion**  
By default there will be a profile that is different from the clion-debug preset  
![Preset-profile-selection-step1](.images/Preset-profile-step1.png)
Disable it and enable the clion-debug (preset) instead, also move it to the top  
![Preset-profile-selection-step2](.images/Preset-profile-step2.png)

Finally, run your code.  

**Visual Studio Code**  

![Run-CMakeToolsExtension](.images/CMake-tools-run.png)

![Running-VScode](.images/Running-code-VScode.png)  

**JetBrains CLion**  

![Running-menu-Clion](.images/Running-menu-CLion.png)

![Running-CLion](.images/Runnnig-code-CLion.png)  

### NOTE:

You can change the Name of your project by modifying the `PROJECT_NAME` parameter in the `CMakeLists.txt` file.  
![Changing-Project-Name](.images/Change-project-name.png)
