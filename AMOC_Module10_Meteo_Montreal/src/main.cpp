#include <Arduino.h>
#include <ArduinoTrace.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
// #define WIFI_SSID "iot_lab_2_no_internet"
// #define WIFI_PASSWORD "engagelejeuquejelegagne"
#define WIFI_SSID "VIRGIN567"
#define WIFI_PASSWORD "AsmaaAbdellatif"

//Variables

String resultat;
int nbEssais = 0, nbEssaisMaximum = 30, nombreHeures = 0, indexe = 0, indexeJour = -1;
float tableauTempMin[7];
float tableauTempMax[7];
float tempMax = -50, tempMin = 50, temperatureMinimaleMoyenne, temperatureMaximaleMoyenne;

//Fonctions

JsonArray deserialiser(String p_resultat);

JsonArray *deserializeJson(DynamicJsonDocument doc, String resultat, DeserializationOption::Filter(StaticJsonDocument<32> filter));

String obtenirTemperatures();

float obtenirTemperatureMoyenne(float temperatures[]);

void afficherTemperature(String p_adresse, int positionCursor);


//Pointeur
LiquidCrystal_I2C *m_lcd;

void setup()
{

  m_lcd = new LiquidCrystal_I2C(0x27, 16, 2);
  m_lcd->init();
  m_lcd->backlight();

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connexion : ");

  while (nbEssais < nbEssaisMaximum && WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    nbEssais++;
  }

  Serial.println("");

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("Connecté au réseau WiFi, adresse IP : ");
    Serial.println(WiFi.localIP());
    Serial.println("");
  }

  if (nbEssais > nbEssaisMaximum && WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Connexion : Echec de connexion");
  }
  resultat = obtenirTemperatures();
  // Serial.println("object recupéré :");
  // Serial.print(res);
  DUMP(resultat);

  JsonArray temperatures = deserialiser(resultat);
  TRACE();
  DUMP(temperatures);
  for (float temperature : temperatures)
  {
    if (nombreHeures % 24 == 0)
    {
      tempMax = -50;
      tempMin = 50;
      ++indexeJour;
    }
    if (temperature > tempMax)
    {
      tempMax = temperature;
    }
    if (temperature < tempMin)
    {
      tempMin = temperature;
    }
    ++nombreHeures;
    tableauTempMax[indexeJour] = tempMax;
    tableauTempMin[indexeJour] = tempMin;
  }
  temperatureMinimaleMoyenne = obtenirTemperatureMoyenne(tableauTempMin);
  temperatureMaximaleMoyenne = obtenirTemperatureMoyenne(tableauTempMax);

  afficherTemperature("Tmp Min : " + String(temperatureMinimaleMoyenne), 0);
  afficherTemperature("Tmp Max : " + String(temperatureMaximaleMoyenne), 1);
}

void loop()
{
  //   for (int i = 0; i < longueur; i++)
  //   {
  //     m_lcd->scrollDisplayLeft();
  //     delay(1000);
  //   }
  //   for (int i = 0; i < longueur + 16; i++)
  //   {

  //     m_lcd->scrollDisplayRight();
  //     delay(1000);
  //   }
  //   for (int i = 0; i < 16; i++)
  //   {
  //     m_lcd->scrollDisplayLeft();
  //     delay(1000);
  //   }
}

String obtenirTemperatures()
{
  String res;
  if (WiFi.status() == WL_CONNECTED)
  {
    String url = "https://api.open-meteo.com/v1/forecast?latitude=45.5017&longitude=-73.5672&hourly=temperature_2m";
    HTTPClient httpClient;
    httpClient.begin(url);
    int codeStatut = httpClient.GET();
    if (codeStatut != 200)
    {
      Serial.println(HTTPClient::errorToString(codeStatut));
    }
    else
    {
      res = httpClient.getString();
    }
  }
  else
  {
    Serial.println("Non connecté au WiFi !");
  }
  return res;
}



JsonArray deserialiser(String p_resultat)
{
  StaticJsonDocument<32> filter;
  filter["hourly"]["temperature_2m"] = true;
  DynamicJsonDocument doc(3072);
  JsonArray temperatures = doc.to<JsonArray>();
  DeserializationError error = deserializeJson(doc, p_resultat, DeserializationOption::Filter(filter));

  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return temperatures;
  }
  temperatures = doc["hourly"]["temperature_2m"].as<JsonArray>();
  return temperatures;
}


float obtenirTemperatureMoyenne(float temperatures[])
{
  float sommeTemperatures = 0;
  for (size_t i = 0; i < 7; i++)
  {
    sommeTemperatures += temperatures[i];
  }

  return (sommeTemperatures / (float)7);
}


void afficherTemperature(String p_temperature, int p_positionCursor)
{
  m_lcd->setCursor(0, p_positionCursor);
  m_lcd->print(p_temperature);
}

