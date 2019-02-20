//-----------------------------------------------------
//ESTE ES EL ÚNICO FICHERO QUE HAY QUE MODIFICAR
//-----------------------------------------------------

#ifndef myStates_H
#define myStates_H

//Declaracion de las funciones
extern void FuncChocar(void);
extern void FuncInicio(void);
extern void FuncST2(void);
extern void FuncST3(void);
extern void FuncST4(void);

//Declaracion del nombre de ESTADOS y de EVENTOS
#define INICIO     1
#define CHOCAR     2
#define PARAR      3
#define DERECHA    4
#define IZQUIERDA  5

#define EV_Reset    0x41
#define EV_Front    0x42
#define EV_Stop     0x43
#define EV_Rear     0x44

const FSMClass::FSM_State_t FSM_State[] PROGMEM = {
  // STATE,STATE_FUNC
  {INICIO, FuncInicio},
  {CHOCAR, FuncChocar},
  {PARAR, FuncST2},
  {DERECHA, FuncST3},
  {IZQUIERDA, FuncST4},
};

const FSMClass::FSM_NextState_t FSM_NextState[] PROGMEM = {
  // STATE,EVENT,NEXT_STATE
  {INICIO, EV_Front, CHOCAR},
  {CHOCAR, EV_Stop, PARAR},
  {CHOCAR, EV_Rear, DERECHA},
  {CHOCAR, EV_Front, IZQUIERDA},
  {PARAR, EV_Reset, CHOCAR},
  {DERECHA, EV_Reset, CHOCAR},
  {IZQUIERDA, EV_Reset, CHOCAR},
};

//Macros para el cálculo de los tamaños de las estructuras
//NO MODIFICAR
#define nStateFcn      sizeof(FSM_State)/sizeof(FSMClass::FSM_State_t)
#define nStateMachine  sizeof(FSM_NextState)/sizeof(FSMClass::FSM_NextState_t)

#endif
