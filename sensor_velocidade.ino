//– Visualizando rpm do cooler com arduino

// Variáveis usadas para os cálculos
int NbTopsFan; 
int Calc;

// Pino utilizado para a leitura no sensor de rotação do cooler
int hallSensor = 2; 
typedef struct{

// Define a estrutura para vários fãs e os divisores
char fanType;
unsigned int fanDiv; 
}

fanspec;

// As definições dos fãs
// Esta é a variável usada para selecionar o cooler e seu divisor,
// 1 para o sensor de efeito Hall unipolar
// E 2 para o sensor de efeito Hall bipolar
fanspec fanspace[3]={{0,1},{1,2},{2,8}}; 
char fan = 1;

void rpm ()

// Esta é a função das chamadas de interrupção
{ NbTopsFan++; }

// Esta é a função de configuração quando a porta serial é inicializada,
// E a interrupção é ligada
void setup(){

pinMode(hallSensor, INPUT);
Serial.begin(9600);
attachInterrupt(0, rpm, RISING); 
}

void loop (){

// Configura a variável NbTops para o cálculo onde as leituras forem 0
NbTopsFan = 0;

// Habilita as interrupções
sei();

// Espera por um segundo
delay (1000);

// Desabilita as interrupções
cli();

// Número de NbTopsFan (que é aproximadamente a freqüência que o 
//cooler está girando) por 60 segundos antes de dividir pelo divisor de fãs
Calc = ((NbTopsFan * 60)/fanspace[fan].fanDiv);

// Imprime o número calculado acima
Serial.print (Calc, DEC);

// Imprimi no Serial Monitor "RPM" e uma nova linha
Serial.print (" RPM\r\n");
}
