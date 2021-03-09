# Documentação da API

## Introdução
  
Esta API foi desenvolvida por Camilla Fernandes e Lucas Hofner para ser utilizada na [AN Aplicação com Pequenos Motores DC](https://github.com/LucasHofner/Carro_MotorCC/blob/master/AN%20-%20Motores%20DC.pdf), como trabalho da disciplina de Programação de Sistemas Embarcados em março de 2021 na Universidade Federal de Minas Gerais. A matéria foi lecionada pelo professor Ricardo de Oliveira Duarte - Departamento de Engenharia Eletrônica. 

A API gerencia o movimento de dois motores CC a partir do controle da ponte H L298N. O movimento, por sua vez, é determinado por 4 botões (fora da API), que são usados como direcionadores:
* Quando o botão Frente é acionado, ambos motores giram no sentido anti-horário, fazendo com que o carro vá para frente
* Quando o botão Trás é acionado, ambos motores giram no sentido horário, fazendo com que o carro vá para trás
* Quando o botão Direita é acionado, o motor da esquerda gira no sentido anti-horário e o da direita no sentido horário, fazendo com que o carro vire para direita
* Quando o botão Equerda é acionado, o motor da esquerda gira no sentido horário e o da direita no sentido anti-horário, fazendo com que o carro vire para esquerda
* Quando nenhum botão é acionado, ambos motores cessam o movimento, fazendo com que o carro fique parado

## Projeto no CubeMX
O primeiro passo - opcional, porém recomendado, é criar um novo projeto no software CubeMX. Esse software pode ser instalado pelo seguinte link
https://www.st.com/en/development-tools/stm32cubemx.html.

Uma vez instalado, acesse o menu "Access to MCU Selector" e selecione seu microcontrolador. No caso, foi selecionado o MCU STM32F103C8T6.

Para a pinagem, é necessário selecionar 4 pinos de entrada com interrupção externa para os botões (GPIO_EXTI) e 4 pinos de saída para controlar a ponte H (GPIO_Output). Para facilitar o desenvolvimento, foram criadas etiquetas endereçando os nomes dos pinos com as conexões a serem feitas (seja com os botões seja com entradas na ponte H). A Figura 1 ilustra a pinagem selecionada:
![Cube_Pinagem](https://github.com/LucasHofner/Carro_MotorCC/blob/master/Images/pinout.PNG)

_Figura 1: Pinagem definida no Cube._

Em seguida, é necessário incluir as interrupções externas definidas no NVIC e definir sua prioridade (foi definida como 2). A Figura 2 ilustra essa operação:

![Cube_int](https://github.com/LucasHofner/Carro_MotorCC/blob/master/Images/interrup.PNG)

_Figura 2: Inclusão das interrupções no NVIC._

Por fim, basta criar o nome para o projeto, selecionar para qual IDE o código será gerado e gerar o código. A Figura 3 ilustra esse processo:

![Cube_code](https://github.com/LucasHofner/Carro_MotorCC/blob/master/Images/codegen.PNG)

_Figura 3: Geração do código._

## Usando a API

Para usar a API basta incluir o arquivo de header no arquivo **main.c** ou **main.h**:
~~~c++
#include "motor.h"
~~~ 

## Hardware
Para essa API, são necessários:
* MCU
* 2 motores DC de 3 a 6V
* Módulo de Ponte H L298N

A Figura 4 mostra a pinagem do módulo de ponte H L298N. É necessário ligar o primeiro motor aos dois terminais de motor A, o segundo motor aos dois terminais do motor B, ligar os 4 pinos de saída definidos no MCU nas conexões IN1, IN2, IN3 e IN4 indicadas. Além disso, esse módulo requere uma alimentação de 6V a 32V para operar os motores. Ainda, ele possui um regulador de tensão de 5V para alimentação de dispositivos externos. Caso seja utilizado, deve ser ligado o jumper "ATIVA 5V". Caso contrário, o pino de 5V deve ser conectado à alimentação do MCU para servir de referência ao nível lógico HIGH. Caso seja utilizado PWM, os jumpers ATIVA MA e MB deve ser desconectados e duas saídas analógicas devem ser ligadas a esses pinos. Nessa aplicação não foi utilizado PWM.

![Pinos_PonteH](https://www.theengineeringprojects.com/wp-content/uploads/2017/07/L298-Pinout.jpg)

_Figura 4: Pinagem L298N._

Opcionalmente, para o controle da ponte H, foi utilizado 4 botões. Esses botões foram ligadas aos pinos definidos como interrupções externas ao MCU.



## Funções API 
No arquivo motor.c e motor.h há um cabeçalho indicando o funcionamento, as entradas e saídas de cada função. As funções disponíveis são:
* moveCarroParaFrente()
* moveCarroParaTras()
* moveCarroParaDireita()
* moveCarroParaEsquerda()
* pararCarro()
