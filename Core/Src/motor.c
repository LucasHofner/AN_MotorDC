/*
 * 	API para a ponte H L298N em conjunto com 2 motores CC (motor.c/motor.h), utilizada
 * 	na AN Aplica��o com Pequenos Motores:
 * 	Autores: Camilla Gomes Fernandes
			 Lucas Guimar�es Hofner
 *  Esta AN e API foi desenvolvida como trabalho da disciplina de Programa��o de Sistemas
 *  Embarcados em mar�o de 2021 na Universidade Federal de Minas Gerais. A mat�ria foi
 *  lecionada pelo professor Ricardo de Oliveira Duarte - Departamento de Engenharia
 *  Eletr�nica.
*/


#include "motor.h"

/* Fun��o: moveCarroParaFrente()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN2 e IN4 e o n�vel LOW para IN1 e IN3.
 *  Isso faz com que ambos os motores girem no sentido anti-hor�rio. Dessa forma, o carro se mover� para frente.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaFrente(){

  uint8_t estadoIN1 = GPIO_PIN_RESET;
  uint8_t estadoIN2 = GPIO_PIN_SET;
  uint8_t estadoIN3 = GPIO_PIN_RESET;
  uint8_t estadoIN4 = GPIO_PIN_SET;

  //Gira o Motor da Esquerda no sentido anti-hor�rio
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido anti-hor�rio
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Fun��o: moveCarroParaDireta()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN1 e IN4 e o n�vel LOW para IN2 e IN3.
 *   Isso faz com que o motor da direta (motor A) gire no sentido hor�rio e o da esquerda (motor B) no sentido anti-hor�rio.
 *   Dessa forma, o carro ir� girar para a direita.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaDireita(){

  uint8_t estadoIN1 = GPIO_PIN_RESET;
  uint8_t estadoIN2 = GPIO_PIN_SET;
  uint8_t estadoIN3 = GPIO_PIN_SET;
  uint8_t estadoIN4 = GPIO_PIN_RESET;

  //Gira o Motor da Esquerda no sentido anti-hor�rio
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido hor�rio
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Fun��o: moveCarroParaTras()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN1 e IN3 e o n�vel LOW para IN2 e IN4.
 *   Isso faz com que ambos os motores girem no sentido hor�rio. Dessa forma, o robo se mover� para tr�s.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaTras(){

  uint8_t estadoIN1 = GPIO_PIN_SET;
  uint8_t estadoIN2 = GPIO_PIN_RESET;
  uint8_t estadoIN3 = GPIO_PIN_SET;
  uint8_t estadoIN4 = GPIO_PIN_RESET;

  //Gira o Motor da Esquerda no sentido hor�rio
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido hor�rio
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Fun��o: moveCarroParaEsquerda()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN2 e IN3 e o n�vel LOW para IN1 e IN4.
 *   Isso faz com que o motor da direta (motor A) gire no sentido anti-hor�rio e o da esquerda (motor B) no sentido hor�rio.
 *   Dessa forma, o robo ir� girar para a esquerda.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaEsquerda(){

  uint8_t estadoIN1 = GPIO_PIN_SET;
  uint8_t estadoIN2 = GPIO_PIN_RESET;
  uint8_t estadoIN3 = GPIO_PIN_RESET;
  uint8_t estadoIN4 = GPIO_PIN_SET;

  //Gira o Motor da Esquerda no sentido hor�rio
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido anti-hor�rio
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Fun��o: pararCarro()
 * Essa fun��o envia o n�vel l�gico HIGH para todos os conectores IN1, IN2, IN3 e IN4.
 *   Isso faz com que os dois motores permane�am parados. N�o havendo nenhuma movimenta��o.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void pararCarro(){

  uint8_t estadoIN1 = GPIO_PIN_SET;
  uint8_t estadoIN2 = GPIO_PIN_SET;
  uint8_t estadoIN3 = GPIO_PIN_SET;
  uint8_t estadoIN4 = GPIO_PIN_SET;

  //Impede o giro do Motor da Esquerda
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Impede o giro do Motor da Direita
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}
