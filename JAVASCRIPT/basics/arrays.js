/* 
Arrays fundamentals with short descriptions and inline comments.
Each numbered block demonstrates a basic array operation or concept.
*/

/* 1. Array declaration and indexing
   - Arrays store ordered collections.
   - Access elements by index (0-based).
*/
let teaFlavors = ["green tea", "black tea", "oolong tea"];
const firstTea = teaFlavors[0]; // "green tea"

/* 2. Another example of indexing
   - Index 2 returns the third element.
*/
let cities = ["London", "Tokyo", "Paris", "New York"];
const favoriteCity = cities[2]; // "Paris"

/* 3. Mutating arrays by index
   - You can change elements directly using their index.
   - Fixed a small spelling mistake in the original item.
*/
let teaTypes = ["herbal tea", "white tea", "masala chai"];
teaTypes[1] = "jasmine tea"; // change "white tea" to "jasmine tea"

/* 4. Adding elements with push()
   - push adds items to the end of the array (mutates the array).
*/
let citiesVisited = ["Mumbai", "Sydney"];
citiesVisited.push("Berlin"); // ["Mumbai", "Sydney", "Berlin"]

/* 5. Removing the last element with pop()
   - pop removes and returns the last element.
*/
let teaOrders = ["chai", "iced tea", "matcha", "earl grey"];
const lastOrder = teaOrders.pop(); // lastOrder = "earl grey", teaOrders now has 3 items

/* 6. Soft (shallow) copy / reference behavior
   - Assigning one array to another copies the reference, not the contents.
   - Mutating the original affects the reference copy.
*/
let popularTeas = ["green tea", "oolong tea", "chai"];
let softCopyTeas = popularTeas; // both variables reference the same array
popularTeas.pop(); // removes "chai" from the shared array
// softCopyTeas now reflects the change because it's the same array

/* 7. Hard (shallow) copy using spread or slice
   - Create a new array with the same elements so mutations don't affect the original.
   - Note: this is a shallow copy; nested objects would still be shared.
*/
let topCities = ["Berlin", "Singapore", "New York"];
let hardCopyCities = [...topCities]; // spread creates a new array copy
// alternatively: let hardCopyCities = topCities.slice();
topCities.pop(); // does not change hardCopyCities

/* 8. Merging arrays with concat (or spread)
   - concat returns a new array combining inputs.
*/
let europeanCities = ["Paris", "Rome"];
let asianCities = ["Tokyo", "Bangkok"];
let worldCities = europeanCities.concat(asianCities);
// or: let worldCities = [...europeanCities, ...asianCities];
// console.log(worldCities); // ["Paris","Rome","Tokyo","Bangkok"]

/* 9. Array length
   - .length gives number of elements.
*/
let teaMenu = ["masala chai", "oolong tea", "green tea", "earl grey"];
let menuLength = teaMenu.length; // 4

/* 10. Checking membership with includes()
   - includes returns true if an element exists in the array.
*/
let cityBucketList = ["Kyoto", "London", "Cape Town", "Vancouver"];
let isLondonInList = cityBucketList.includes("London"); // true

// End of fundamentals: declaration, indexing, mutation, push/pop, references vs copies, merging, length, membership.
