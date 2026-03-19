# Spinning Donut (ASCII)

Animação em terminal de um toro 3D ("donut") renderizado em ASCII em tempo real, com rotação contínua.

## Objetivo
Projeto de estudo para demonstrar:
- projeção 3D em 2D;
- sombreamento simples por luminância;
- z-buffer em grade de caracteres;
- animação em loop no terminal com escape ANSI.

## Tecnologias
- C (C99+)
- `math.h` (`sin`, `cos`)
- `unistd.h` (`usleep`)
- Terminal ANSI

## Como rodar
### Linux/macOS
```bash
gcc donut.c -lm -O2 -o donut
./donut
```

> Para encerrar, use `Ctrl+C`.

## Estrutura
```text
.
├── donut.c     # implementação única da renderização
└── README.md
```

## Mecânicas implementadas
- Malha paramétrica do toro por amostragem angular (`i`, `j`)
- Rotação por dois ângulos independentes (`A`, `B`)
- Projeção perspectiva para coordenadas de tela (`x`, `y`)
- Teste de profundidade (`z[]`) para ocultação de superfície
- Mapeamento de brilho para charset (`.,-~:;=!*#$@`)
- Refresh de frame com reposicionamento de cursor (`\x1b[H`)

## Estado atual
- Funcional e executável como demonstração técnica compacta.
- Código intencionalmente minimalista em um único arquivo.

## Limitações
- Sem modularização, testes, CLI ou configuração.
- Dependente de terminal com suporte ANSI.
- Dimensões de tela fixas (80x22 úteis na matriz 80x22/1760).
- Loop infinito sem tratamento de sinais para encerramento gracioso.

## Melhorias futuras (incrementais)
- Extrair funções (`render_frame`, `project_point`, `compute_luminance`).
- Parametrizar FPS, tamanho de tela e velocidade de rotação.
- Detectar dimensões do terminal em runtime.
- Adicionar Makefile e flags de build/documentação.

## Aprendizados
Este projeto é útil para consolidar fundamentos de computação gráfica em baixo nível sem dependências externas: transformação geométrica, projeção, profundidade e sombreamento discreto.
