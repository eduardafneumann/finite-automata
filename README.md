Como estamos compilando estaticamente, instale os pacotes glibc-static e libstdc++-static. No Fedora, por exemple, execute:

```
sudo dnf install libstdc++-static glibc-static
```

Para executar, rode no diretório raíz:

```
make
```

```
make run
```