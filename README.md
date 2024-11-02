# Projeto Integrador VI - Turma B: Simulador de Semáforo com Arduino

Este projeto simula o funcionamento de um semáforo utilizando um Arduino Uno, LEDs e um botão para a travessia de pedestres, desenvolvido no Tinkercad.

![Simulador de Semáforo](/semaforo.png)


## Descrição do Projeto

Este projeto implementa um semáforo com três LEDs (vermelho, amarelo e verde) controlados por um Arduino Uno.  O sistema alterna as luzes do semáforo em intervalos específicos, simulando o funcionamento de um semáforo real.  Além disso, um botão permite simular a solicitação de travessia de pedestres, alterando o ciclo do semáforo para garantir a segurança.

## Funcionamento

O semáforo opera em um ciclo contínuo, com os seguintes tempos para cada LED:

* **Vermelho:** 5 segundos
* **Amarelo:** 2 segundos
* **Verde:** 5 segundos

Ao pressionar o botão de pedestre, o semáforo interrompe o ciclo normal e realiza a seguinte sequência:

* Se o verde estiver aceso, ele é desligado e o amarelo acende por 2 segundos.
* Em seguida, o vermelho acende por 5 segundos, permitindo a travessia segura dos pedestres.
* Após a travessia, o ciclo normal do semáforo é retomado.

## Componentes Utilizados

* Arduino Uno R3
* LEDs: 1 Vermelho, 1 Amarelo, 1 Verde
* Resistores: 3 resistores de 220 ohms (ou valor apropriado para seus LEDs)
* Botão de pressão (Push Button)
* Protoboard
* Jumpers

## Montagem

O circuito é montado em uma protoboard, conectando os componentes ao Arduino Uno conforme o diagrama esquemático. As conexões dos LEDs e do botão ao Arduino são feitas através de resistores para limitar a corrente e proteger os componentes.  Certifique-se de conectar os LEDs corretamente, observando a polaridade (perna mais longa é o positivo).


## Código-Fonte

O código-fonte para o Arduino está disponível neste repositório no arquivo `epic_wolt1.ino`.