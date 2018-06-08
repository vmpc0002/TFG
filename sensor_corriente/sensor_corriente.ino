float SENSIBILITY=0.1; //Utilizamos 0.1 debido a nuestras especificaciones del modelo de 20A
int SAMPLESNUMBER=500; //Numero de muestras
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void printMeasure(String prefix, float value, String postfix){
  Serial.print(prefix);
  Serial.print(value, 3);
  Serial.println(postfix);
}

float getCorriente(int samplesNumber){
  float voltage;
  float currentSum=0;
  for(int i=0;i<samplesNumber;i++){
    voltage=analogRead(A0)*5.0/1023.0; //Normalizamos el valor obtenido, ya que el valor maximo
    //que ofrece esta lectura es 1023 para una lectura de 5V, así que multiplicamos por 5 y
    //dividimos pr 1023 para obtener nuestro valor real.
    currentSum +=(voltage-2.5)/SENSIBILITY; //Formula que nos indica el fabricante.
  }
  return (currentSum/samplesNumber);
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  float current=getCorriente(SAMPLESNUMBER); //LE RESTASMOS 0.06543 porque es el valor de corriente que mete el sensor sin carga. Lo hemos calculado tras 30 muestras obtenidas calculando su media.
  float currentRMS=0.707*current;
  float power=230.0*currentRMS;

  printMeasure("Intensidad:", current, "A,");
 // printMeasure("Irms: ", currentRMS, "A,");
 // printMeasure("Potencia: ", power, "W");
}
