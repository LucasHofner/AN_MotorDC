/*
 * 	API para a ponte H L298N em conjunto com 2 motores CC (motor.c/motor.h), utilizada
 * 	na AN Aplicação com Pequenos Motores CC:
 * 	Autores: Camilla Gomes Fernandes
			 Lucas Guimarães Hofner
 *  Esta AN e API foi desenvolvida como trabalho da disciplina de Programação de Sistemas
 *  Embarcados em março de 2021 na Universidade Federal de Minas Gerais. A matéria foi
 *  lecionada pelo professor Ricardo de Oliveira Duarte - Departamento de Engenharia
 *  Eletrônica.
*/

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f1xx_hal.h"
#include "stdbool.h"
#include "main.h"

#define IN1_PORTO IN1_GPIO_Port
#define IN2_PORTO IN2_GPIO_Port
#define IN3_PORTO IN3_GPIO_Port
#define IN4_PORTO IN4_GPIO_Port
#define IN1_PINO IN1_Pin
#define IN2_PINO IN2_Pin
#define IN3_PINO IN3_Pin
#define IN4_PINO IN4_Pin


/* Função: moveCarroParaFrente()
 * Essa função envia o nível lógico HIGH para os conectores IN2 e IN4 e o nível LOW para IN1 e IN3.
 *  Isso faz com que ambos os motores girem no sentido anti-horário. Dessa forma, o carro se moverá para frente.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaFrente();

/* Função: moveCarroParaDireta()
 * Essa função envia o nível lógico HIGH para os conectores IN1 e IN4 e o nível LOW para IN2 e IN3.
 *   Isso faz com que o motor da direta (motor A) gire no sentido horário e o da esquerda (motor B) no sentido anti-horário.
 *   Dessa forma, o carro irá girar para a direita.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaDireita();

/* Função: moveCarroParaTras()
 * Essa função envia o nível lógico HIGH para os conectores IN1 e IN3 e o nível LOW para IN2 e IN4.
 *   Isso faz com que ambos os motores girem no sentido horário. Dessa forma, o robo se moverá para trás.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaTras();

/* Função: moveCarroParaEsquerda()
 * Essa função envia o nível lógico HIGH para os conectores IN2 e IN3 e o nível LOW para IN1 e IN4.
 *   Isso faz com que o motor da direta (motor A) gire no sentido anti-horário e o da esquerda (motor B) no sentido horário.
 *   Dessa forma, o robo irá girar para a esquerda.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void moveCarroParaEsquerda();

/* Função: pararCarro()
 * Essa função envia o nível lógico HIGH para todos os conectores IN1, IN2, IN3 e IN4.
 *   Isso faz com que os dois motores permaneçam parados. Não havendo nenhuma movimentação.
 * Parâmetros: não há parâmetros para essa função.
 * Não há retorno para essa função
 */
void pararCarro();

#endif /* INC_MOTOR_H_ */
