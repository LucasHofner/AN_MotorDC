/*
 * 	API para a ponte H L298N em conjunto com 2 motores CC (motor.c/motor.h), utilizada
 * 	na AN Aplica��o com Pequenos Motores CC:
 * 	Autores: Camilla Gomes Fernandes
			 Lucas Guimar�es Hofner
 *  Esta AN e API foi desenvolvida como trabalho da disciplina de Programa��o de Sistemas
 *  Embarcados em mar�o de 2021 na Universidade Federal de Minas Gerais. A mat�ria foi
 *  lecionada pelo professor Ricardo de Oliveira Duarte - Departamento de Engenharia
 *  Eletr�nica.
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


/* Fun��o: moveCarroParaFrente()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN2 e IN4 e o n�vel LOW para IN1 e IN3.
 *  Isso faz com que ambos os motores girem no sentido anti-hor�rio. Dessa forma, o carro se mover� para frente.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaFrente();

/* Fun��o: moveCarroParaDireta()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN1 e IN4 e o n�vel LOW para IN2 e IN3.
 *   Isso faz com que o motor da direta (motor A) gire no sentido hor�rio e o da esquerda (motor B) no sentido anti-hor�rio.
 *   Dessa forma, o carro ir� girar para a direita.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaDireita();

/* Fun��o: moveCarroParaTras()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN1 e IN3 e o n�vel LOW para IN2 e IN4.
 *   Isso faz com que ambos os motores girem no sentido hor�rio. Dessa forma, o robo se mover� para tr�s.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaTras();

/* Fun��o: moveCarroParaEsquerda()
 * Essa fun��o envia o n�vel l�gico HIGH para os conectores IN2 e IN3 e o n�vel LOW para IN1 e IN4.
 *   Isso faz com que o motor da direta (motor A) gire no sentido anti-hor�rio e o da esquerda (motor B) no sentido hor�rio.
 *   Dessa forma, o robo ir� girar para a esquerda.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void moveCarroParaEsquerda();

/* Fun��o: pararCarro()
 * Essa fun��o envia o n�vel l�gico HIGH para todos os conectores IN1, IN2, IN3 e IN4.
 *   Isso faz com que os dois motores permane�am parados. N�o havendo nenhuma movimenta��o.
 * Par�metros: n�o h� par�metros para essa fun��o.
 * N�o h� retorno para essa fun��o
 */
void pararCarro();

#endif /* INC_MOTOR_H_ */
