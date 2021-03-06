/**The MIT License (MIT)

Copyright (c) 2015 by Daniel Eichhorn

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

See more at http://blog.squix.ch
*/

#pragma once

#include <JsonListener.h>
#include <JsonStreamingParser.h>

#define MAX_FORECAST_PERIODS 7

class WundergroundClient: public JsonListener {
  private:
    String currentKey;
    String currentParent = "";
    long localEpoc = 0;
    int gmtOffset = 1;
    long localMillisAtUpdate;
    String date = "-";
    boolean isMetric = true;
    String currentTemp;
    String weatherIcon;
    String weatherText;
    String humidity;
    String pressure;
    String precipitationToday;
    void doUpdate(String url);

    // forecast
    boolean isForecast = false;
    boolean isSimpleForecast = true;
    int currentForecastPeriod;
    String forecastIcon [MAX_FORECAST_PERIODS];
    String forecastTitle [MAX_FORECAST_PERIODS];
    String forecastLowTemp [MAX_FORECAST_PERIODS];
    String forecastHighTemp [MAX_FORECAST_PERIODS];
    
    // astronomy
    String sunrise;
    String sunset;
    String currentTime;
    
    //geolookup - autolocation
    String country;
    String country_iso3166;
    String country_name;
    String state;
    String city;
    String tz_short;
    String tz_long;
    String lat;
    String lon;
    String zip;
    String magic;
    String wmo;
    String l;
    String requesturl;
    String wuiurl;

  public:
    WundergroundClient(boolean isMetric);
    void updateConditions(String apiKey, String country, String city);
    void updateForecast(String apiKey, String country, String city);
    void updateAstronomy(String apiKey, String country, String city);
    void geolookup(String apiKey);
    String getHours();
    String getMinutes();
    String getSeconds();
    String getDate();
    long getCurrentEpoch();
    
    //functions for returning Astronomy data
    String getSunrise();
    String getSunset();
    String getCurrentTime();
//    String getMoonAge();
//    String getPercentIlluminated();

	//functions for returning location data
	String getCountry();
    //String getCountry_iso3166();
    //String getCountry_name();
    String getState();
    String getCity();
    String getTZ_short();
    String getTZ_long();
// String getLat();
//     String getLon();
//     String getZip;
//     String getMagic;
//     String getWmo;
//     String getL;
//     String getRequesturl;
//     String getWuiurl;

    String getCurrentTemp();

    String getTodayIcon();

    String getMeteoconIcon(String iconText);

    String getWeatherText();

    String getHumidity();

    String getPressure();

    String getPrecipitationToday();

    String getForecastIcon(int period);

    String getForecastTitle(int period);

    String getForecastLowTemp(int period);

    String getForecastHighTemp(int period);

    virtual void whitespace(char c);

    virtual void startDocument();

    virtual void key(String key);

    virtual void value(String value);

    virtual void endArray();

    virtual void endObject();

    virtual void endDocument();

    virtual void startArray();

    virtual void startObject();
};
