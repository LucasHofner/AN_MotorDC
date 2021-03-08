/*
 * 	API para a ponte H L298N em conjunto com 2 motores CC (motor.c/motor.h), utilizada
 * 	na AN Aplicação com Pequenos Motores:
 * 	Autores: Camilla Gomes Fernandes
			 Lucas Guimarães Hofner
 *  Esta AN e API foi desenvolvida como trabalho da disciplina de Programação de Sistemas
 *  Embarcados em março de 2021 na Universidade Federal de Minas Gerais. A matéria foi
 *  lecionada pelo professor Ricardo de Oliveira Duarte - Departamento de Engenharia
 *  Eletrônica.
*/


#include "motor.h"

/* Função: moveCarroParaFrente()
 * Essa função envia o nível lógico HIGH para os conectores IN2 e IN4 e o nível LOW para IN1 e IN3.
 *  Isso faz com que ambos os motores girem no sentido anti-horário. Dessa forma, o carro se moverá para frente.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaFrente(){

  uint8_t estadoIN1 = GPIO_PIN_RESET;
  uint8_t estadoIN2 = GPIO_PIN_SET;
  uint8_t estadoIN3 = GPIO_PIN_RESET;
  uint8_t estadoIN4 = GPIO_PIN_SET;

  //Gira o Motor da Esquerda no sentido anti-horário
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido anti-horário
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Função: moveCarroParaDireta()
 * Essa função envia o nível lógico HIGH para os conectores IN1 e IN4 e o nível LOW para IN2 e IN3.
 *   Isso faz com que o motor da direta (motor A) gire no sentido horário e o da esquerda (motor B) no sentido anti-horário.
 *   Dessa forma, o carro irá girar para a direita.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaDireita(){

  uint8_t estadoIN1 = GPIO_PIN_RESET;
  uint8_t estadoIN2 = GPIO_PIN_SET;
  uint8_t estadoIN3 = GPIO_PIN_SET;
  uint8_t estadoIN4 = GPIO_PIN_RESET;

  //Gira o Motor da Esquerda no sentido anti-horário
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido horário
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Função: moveCarroParaTras()
 * Essa função envia o nível lógico HIGH para os conectores IN1 e IN3 e o nível LOW para IN2 e IN4.
 *   Isso faz com que ambos os motores girem no sentido horário. Dessa forma, o robo se moverá para trás.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaTras(){

  uint8_t estadoIN1 = GPIO_PIN_SET;
  uint8_t estadoIN2 = GPIO_PIN_RESET;
  uint8_t estadoIN3 = GPIO_PIN_SET;
  uint8_t estadoIN4 = GPIO_PIN_RESET;

  //Gira o Motor da Esquerda no sentido horário
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido horário
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Função: moveCarroParaEsquerda()
 * Essa função envia o nível lógico HIGH para os conectores IN2 e IN3 e o nível LOW para IN1 e IN4.
 *   Isso faz com que o motor da direta (motor A) gire no sentido anti-horário e o da esquerda (motor B) no sentido horário.
 *   Dessa forma, o robo irá girar para a esquerda.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaEsquerda(){

  uint8_t estadoIN1 = GPIO_PIN_SET;
  uint8_t estadoIN2 = GPIO_PIN_RESET;
  uint8_t estadoIN3 = GPIO_PIN_RESET;
  uint8_t estadoIN4 = GPIO_PIN_SET;

  //Gira o Motor da Esquerda no sentido horário
  HAL_GPIO_WritePin(IN1_PORTO,IN1_PINO, estadoIN1);
  HAL_GPIO_WritePin(IN2_PORTO,IN2_PINO, estadoIN2);

  //Gira o Motor da Direita no sentido anti-horário
  HAL_GPIO_WritePin(IN3_PORTO,IN3_PINO, estadoIN3);
  HAL_GPIO_WritePin(IN4_PORTO,IN4_PINO, estadoIN4);

}

/* Função: pararCarro()
 * Essa função envia o nível lógico HIGH para todos os conectores IN1, IN2, IN3 e IN4.
 *   Isso faz com que os dois motores permaneçam parados. Não havendo nenhuma movimentação.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
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
