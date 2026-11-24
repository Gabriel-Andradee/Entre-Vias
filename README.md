# 🚦 Entre-Vias

Projeto desenvolvido com o objetivo de proporcionar maior previsibilidade, eficiência, segurança e praticidade durante os deslocamentos.

## 📋 Sobre o Projeto
Sistema embarcado baseado em Arduino que utiliza sensores ultrassônicos para monitorar distâncias e emitir alertas visuais (LEDs RGB) e sonoros (Buzzer) para auxiliar na segurança e controle de fluxo.

## 🛠️ Componentes Utilizados
* 1x Tela TFT-Shield 3,5 Polegadas
* 2x Placa Arduino (Uno / Nano)
* 2x Sensores Ultrassônicos (HC-SR04)
* 2x LEDs RGB
* 2x Alto-Falante
* 1x Botão (Push Button)
* Jumpers e Resistores
* 1x Base de isopor 100X50cm
* 1x MDF 150X100cm
* 2x PVA Branca
* 3x PVA Verde
* 1x PVA Cinza
* 1x TeckBond
* 1x Fita led RGB 1m

## 🔌 Pinagem (Conexões no Arduino)

| Componente | Pino no Arduino | Função |
| :--- | :---: | :--- |
| **Sensor 1 (Trig / Echo)** | `2` / `4` | Medição de distância - Via 1 |
| **Sensor 2 (Trig / Echo)** | `7` / `8` | Medição de distância - Via 2 |
| **LED 1 (R / G / B)** | `3` / `5` / `6` | Sinalização visual - Via 1 |
| **LED 2 (R / G / B)** | `9` / `10` / `11` | Sinalização visual - Via 2 |
| **Botão** | `12` | Acionamento / Controle manual |
| **Buzzer** | `13` | Alerta sonoro |

## 📚 Bibliotecas Necessárias
* `Ultrasonic.h`

## 🚀 Como Executar
1. Baixe ou clone este repositório.
2. Abra o arquivo de código na **Arduino IDE**.
3. Instale a biblioteca `Ultrasonic` através do Gerenciador de Bibliotecas da IDE.
4. Conecte o Arduino via USB, selecione a porta correta e clique em **Carregar (Upload)**.

## 👥 Equipe
* **Gabriel Andrade** - [@Gabriel-Andradee](https://github.com/Gabriel-Andradee)
* **Gabriel Guimarães** - [@Gabriel-Guimaraes-c](https://github.com/Gabriel-Guimaraes-c)
* **Luis Gabriel** - [@luis-lippo](https://github.com/Luis-Gabriel)
* **Caua Victor** - [@cvps2-maker](https://github.com/cvps2)
* **Lorena Ohana**
* *[Adicione aqui o nome e link do GitHub dos seus amigos]*
