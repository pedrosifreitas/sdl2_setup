# sdl2_setup
Um setup básico de SDL

Esse repositório serve apenas como setup básico para um projeto SDL2 e não possui uma cópia da biblioteca. Para usá-la, siga as instruções abaixo:

## Instalação do SDL2:

- Vá no repositório do [MSYS2](https://github.com/msys2/msys2-installer/releases/tag/nightly-x86_64) e instale o arquivo **"msys2-x86_64-latest.exe"**

- Abra o arquivo e siga com o processo de instalação. Sugiro que use as configurações padrões do instalador.

- Uma vez instalado, abra a pasta onde o MSYS2 foi instalado (geralmente fica em ```C:/msys2```), abra o programa "mingw64.exe" e use os seguintes comandos (você deve colar com ```SHIFT + INSERT``` no Bash):
  - ```pacman -Syu```
    - Atualizará o MSYS2 se houver atualizações pendentes
  - ```pacman -S git mingw-w64-x86_64-gcc mingw-w64-x86_64-toolchain mingw64/mingw-w64-x86_64-SDL2 mingw64/mingw-w64-x86_64-SDL2_mixer mingw64/mingw-w64-x86_64-SDL2_image mingw64/mingw-w64-x86_64-SDL2_ttf mingw64/mingw-w64-x86_64-SDL2_net mingw64/mingw-w64-x86_64-cmake make```
    - Instalará o pacote do SDL no seu computador

- Uma vez instalado, instale esse repositório, se não o fez ainda, e o abra no Visual Studio Code (clique com o botão direito e selecione "Abrir com Code"). Lembre-se de instalar a extensão C/C++ no Code! Abra o arquivo ```c_cpp_proprieties.json``` no Code e certifique-se de que o arquivo está EXATAMENTE desse jeito:
```
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:\\msys64\\mingw64\\include\\SDL2"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "cStandard": "c17",
            "cppStandard": "gnu++14",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```
Se estiver, prossiga. Se não estiver, copie o código acima, cole no arquivo e salve.

Se você conseguiu fazer isso, você conseguiu instalar com sucesso o SDL2. Para certificar que tudo está funcionando corretamente, siga as instruções abaixo para compilar o projeto pelo Bash do MSYS2

## Compilando o projeto

### Usando o MSYS2 no VS Code

Para simplificar a sua vida, eis um tutorial rápido de como usar o Bash do MSYS2 no VS COde

- Clique no ícone de engrenagem :gear: no canto inferior esquerdo e selecione configurações
- Pesquise por ```terminal.integrated.profiles.windows``` na barra de pesquisa do menu de Configurações
- Clique em "Editar em settings.json"
- No arquivo settings.json, coloque entre as chaves "{}" depois de ```terminal.integrated.profiles.windows```, copie e cole:
```
//...
"MSYS2 MINGW64": {
            "path": "cmd.exe",
            "args": [
                "/c",
                "C:\\msys64\\msys2_shell.cmd -defterm -here -no-start -mingw64"
            ]
        },
//...
```

Seu arquivo deve ficar mais ou menos assim (não precisar estar exatamente assim):
```
{
	"terminal.integrated.profiles.windows": {
        	"MSYS2 MINGW64": {
            		"path": "cmd.exe",
            		"args": [
                		"/c",
                		"C:\\msys64\\msys2_shell.cmd -defterm -here -no-start -mingw64"
            		]
        	},
          //outros terminais
        	"PowerShell": {
            		"source": "PowerShell",
            		"icon": "terminal-powershell"
        	},
        	"Command Prompt": {
            		"path": [
                		"${env:windir}\\Sysnative\\cmd.exe",
                		"${env:windir}\\System32\\cmd.exe"
            		],
            		"args": [],
            		"icon": "terminal-cmd"
        	},
	}
}
```

### Compilando o projeto pelo MSYS2
Até que enfim!

- Se você NÃO estiver usando o MSYS2 pelo VS Code, use o comando ```cd``` para abrir a pasta do seu projeto
- Para compilar, use o comando ```gcc main.c -o bin/teste.exe $(pkg-config --cflags --libs sdl2)```

Se o repositório estiver funcionando corretamente e a instalação estiver sido feita de forma correta, a compilação deve ocorrer sem problemas.

Vá na pasta ```bin``` e abra o arquivo ```teste.exe```. O programa deverá abrir uma tela preta que fecha ao pressionar ESC.

Parabéns, você conseguiu instalar o SDL2 e fazer o projeto funcionar!
