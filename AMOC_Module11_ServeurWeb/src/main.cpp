#include "SPIFFS.h"
#include <ArduinoTrace.h>

void listFilesInDir(File dir, int numTabs = 1);

void setup()
{
  TRACE();
  Serial.begin(112500);
  TRACE();
  delay(500);
  TRACE();
  Serial.println(F("Inizializing FS..."));
  TRACE();
  if (SPIFFS.begin())
  {
    TRACE();
    Serial.println(F("SPIFFS mounted correctly."));
  }
  else
  {
    Serial.println(F("!An error occurred during SPIFFS mounting"));
  }

  // Get all information of SPIFFS

  unsigned int totalBytes = SPIFFS.totalBytes();
  TRACE();
  DUMP(totalBytes);
  unsigned int usedBytes = SPIFFS.usedBytes();
  TRACE();
  DUMP(usedBytes);

  Serial.println("===== File system info =====");

  Serial.print("Total space:      ");
  Serial.print(totalBytes);

  Serial.println("byte");

  Serial.print("Total space used: ");
  Serial.print(usedBytes);
  Serial.println("byte");

  Serial.println();

  // Open dir folder
  File dir = SPIFFS.open("/");
  TRACE();
  DUMP(dir);
  // List file at root
  listFilesInDir(dir);
  TRACE();
}

void listFilesInDir(File dir, int numTabs)
{
  while (true)
  {

    File entry = dir.openNextFile();
      DUMP(entry);
    if (!entry)
    {
      // no more files in the folder
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++)
    {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory())
    {
      Serial.println("/");
      listFilesInDir(entry, numTabs + 1);
    }
    else
    {
      // display zise for file, nothing for directory
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

void loop()
{
}