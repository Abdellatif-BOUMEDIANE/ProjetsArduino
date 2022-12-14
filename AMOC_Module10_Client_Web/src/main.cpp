#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
// #define WIFI_SSID "iot_lab_2_no_internet"
// #define WIFI_PASSWORD "engagelejeuquejelegagne"
#define WIFI_SSID "VIRGIN567"
#define WIFI_PASSWORD "AsmaaAbdellatif"

String res = "";

int nbEssais = 0;
int nbEssaisMaximum = 30;

void AllumerDELInterne(int p_duree);

void EteindreDELInterne(int p_duree);

String obtenirIPPublique();

String deserialiser(String p_json);

void afficherAdresseLocale(String p_adresse);

void afficherAdressePublique(String p_adresse);

LiquidCrystal_I2C *m_lcd;
int longueur;
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
    longueur = ("Ip locale : " + WiFi.localIP().toString()).length();
    Serial.println(longueur);
    Serial.println("");
    afficherAdresseLocale("Ip locale : " + WiFi.localIP().toString());
    delay(1000);
  }

  if (nbEssais > nbEssaisMaximum && WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Connexion : Echec de connexion");
  }

  res = obtenirIPPublique();
  Serial.println("object recupéré :");
  Serial.print(res);

  String resultatIp = deserialiser(res);

  Serial.println("Adresse publique recupérée :");
  Serial.print(resultatIp);
  afficherAdressePublique("Ip publique : " + resultatIp);
}

void loop()
{

  for (int i = 0; i < longueur; i++)
  {
    m_lcd->scrollDisplayLeft();
    delay(1000);
  }
  for (int i = 0; i < longueur + 16; i++)
  {

    m_lcd->scrollDisplayRight();
    delay(1000);
  }
  for (int i = 0; i < 16; i++)
  {
    m_lcd->scrollDisplayLeft();
    delay(1000);
  }
}

void AllumerDELInterne(int p_duree)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);
}

void EteindreDELInterne(int p_duree)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);
}

String obtenirIPPublique()
{
  String res = "";
  if (WiFi.status() == WL_CONNECTED)
  {
    String url = "https://ifconfig.co/json";
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

String deserialiser(String p_json)
{
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, res);
  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return "error";
  }

  const String ippu = doc["ip"]; // "199.202.104.106"
  return ippu;
}
void afficherAdresseLocale(String p_adresse)
{
  m_lcd->setCursor(0, 0);
  m_lcd->print(p_adresse);
}
void afficherAdressePublique(String p_adresse)
{
  m_lcd->setCursor(0, 1);
  m_lcd->print(p_adresse);
}