#ifndef S4power_h
#define S4power_h

//Defini��o de estrutura para controlador de Motor (L298N) 
 struct MotorConf 
  {
      char pinDir1;
      char pinDir2;
      char pinPwm;
  };
  
  //Defini��o de estrutura para controlador de Ilumina��o (MOSFET)
struct LightConf 
  {
      char pinPwm;    
      char pinSensor;
  };

class Motor
{
public:
      MotorConf conf; //Configura��o do seu controlador 
      char speed;     //Valor da sua velocidade (-100 a 100)
  
      //Configura o controlador 
      void SetConf ( char pinDir1, char pinDir2, char pinPwm ) ;
        
      //Atualiza o valor de velocidade para o controlador 
      void Update ( void ) ;

      //Converte o valor de velocidade para PWM ( velocidade 100 = 255 no PWM )
      char ConvertToPwm ( char speed ) ;
};

class Light
  {
    public:
      LightConf conf;//Configura��es do controlador de ilumina��o (MOSFET)
      char intensity;//Valor da intensidade da ilumina��o 
      int power;//Consumo do led em miliamperes
  
      //Configura o controlador 
      void SetConf ( char pinPwm, char pinSensor ) ;
      
  
      //Atualiza o valor de intensidade para o controlador 
      void Update ( void ) ;
     
  
      //Converte valor de leitura analógica para miliamperes
      int ConvertToPower ( int analogSensor );
      
  
      //Converte o valor de intensidade para PWM ( intensidade 100 = 255 no PWM )
      char ConvertToPwm ( char intensity ) ;
      
  };

class S4Power
  {
   public:
      Motor M1;//Motor 1 
      Motor M2;//Motor 2 
      Motor M3;//Motor 3
      Motor M4;//Motor 4
      Light light;//Ilumina��o 
	void Config ( );
  };

#endif
