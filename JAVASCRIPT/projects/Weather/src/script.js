document.addEventListener("DOMContentLoaded", () => {
  const enterCity = document.getElementById("city-input");
  const getWeather = document.getElementById("get-weather-btn");
  const getInfo = document.getElementById("weather-info");
  const cityInfo = document.getElementById("city-name");
  const tempInfo = document.getElementById("temperature");
  const descInfo = document.getElementById("description");
  const windInfo = document.getElementById("wind");
  const errorMessage = document.getElementById("error-message");

  getWeather.addEventListener("click", async () => {
    const city = enterCity.value.trim();
    if (!city) return;

    try {
      const fetchweather = await getWeatherData(city);
      displayWeatherData(fetchweather);
    } catch (error) {
      displayError();
    }
  });

  async function getWeatherData(city) {
    const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`;
    const response = await fetch(url);
    console.log(response);
    console.log(typeof response);

    if (!response.ok) {
      throw new Error("City not found");
    }
    const data = await response.json();
    return data;
  }

  function displayWeatherData(weatherData) {
    console.log(weatherData);
    const { name, main, weather, wind } = weatherData;
    cityInfo.textContent = "City: " + name;
    tempInfo.textContent = "Currently: " + main.temp + "°C";
    descInfo.textContent = "Feels like: " + weather[0].description;
    windInfo.textContent =
      "Wind speeds: " + ((wind.speed * 18) / 5).toFixed(2) + "km/hr";
    getInfo.classList.remove("hidden");
    errorMessage.classList.add("hidden");
  }

  function displayError(error) {
    getInfo.classList.add("hidden");
    errorMessage.classList.remove("hidden");
  }
});
