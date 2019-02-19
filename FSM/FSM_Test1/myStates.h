//-----------------------------------------------------
//ESTE ES EL ÚNICO FICHERO QUE HAY QUE MODIFICAR
//-----------------------------------------------------

#ifndef myStates_H
#define myStates_H

//Declaracion de las funciones
extern void func2(void);

//Declaracion del nombre de ESTADOS y de EVENTOS
#define STATE1  	0x01
#define STATE2  	0x02

#define EV_Cambia   0x41
#define EV_Reset	0x42

const FSMClass::FSM_State_t FSM_State[] PROGMEM = {
  // STATE,STATE_FUNC
  {STATE1, 0},
  {STATE2, func2},
};

const FSMClass::FSM_NextState_t FSM_NextState[] PROGMEM = {
  // STATE,EVENT,NEXT_STATE
  {STATE1, EV_Cambia, STATE2},
  {STATE2, EV_Reset, STATE1},
};

//Macros para el cálculo de los tamaños de las estructuras
//NO MODIFICAR
#define nStateFcn		    sizeof(FSM_State)/sizeof(FSMClass::FSM_State_t)
#define nStateMachine		sizeof(FSM_NextState)/sizeof(FSMClass::FSM_NextState_t)

#endif

