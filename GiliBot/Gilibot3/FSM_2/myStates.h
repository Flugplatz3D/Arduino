//-----------------------------------------------------
//ESTE ES EL ÚNICO FICHERO QUE HAY QUE MODIFICAR
//-----------------------------------------------------

#ifndef myStates_H
#define myStates_H

//Declaracion de las funciones
extern void FuncChocar(void);
extern void FuncInicio(void);
extern void FuncParar(void);
extern void FuncDerecha(void);
extern void FuncIzquierda(void);

//Declaracion del nombre de ESTADOS y de EVENTOS
#define INICIO     1
#define CHOCAR     2
#define PARAR      3
#define DERECHA    4
#define IZQUIERDA  5
#define ESPERAR    6

#define EV_Front    0x41
#define EV_Stop     0x42
#define EV_Reset    0x43
#define EV_Rear     0x44
#define EV_Inicio   0x45
#define EV_Left     0x46
#define EV_Right    0x47

const FSMClass::FSM_State_t FSM_State[] PROGMEM = {
  // STATE,STATE_FUNC
  {INICIO, FuncInicio},
  {CHOCAR, FuncChocar},
  {PARAR, FuncParar},
  {DERECHA, FuncDerecha},
  {IZQUIERDA, FuncIzquierda}
};

const FSMClass::FSM_NextState_t FSM_NextState[] PROGMEM = {
  // STATE,EVENT,NEXT_STATE
  {INICIO, EV_Front, INICIO},
  {INICIO, EV_Inicio, CHOCAR},
  {CHOCAR, EV_Front, CHOCAR},
  {CHOCAR, EV_Stop, PARAR},
  {PARAR, EV_Stop, PARAR},
  {PARAR, EV_Left, IZQUIERDA},
  {IZQUIERDA, EV_Left, IZQUIERDA}
};

//Macros para el cálculo de los tamaños de las estructuras
//NO MODIFICAR
#define nStateFcn      sizeof(FSM_State)/sizeof(FSMClass::FSM_State_t)
#define nStateMachine  sizeof(FSM_NextState)/sizeof(FSMClass::FSM_NextState_t)

#endif
