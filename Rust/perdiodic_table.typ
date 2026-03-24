// Moscow Table Template
// Russian style periodic table - 18 columns, shell-based arrangement

// Element data structure
// Each element has: symbol, number, name, category
const elements = {
  // Period 1
  [1]:  { symbol: "H", name: "Hydrogen", category: "nonmetal", group: 1 },
  [2]:  { symbol: "He", name: "Helium", category: "noble", group: 18 },
  
  // Period 2
  [3]:  { symbol: "Li", name: "Lithium", category: "alkali", group: 1 },
  [4]:  { symbol: "Be", name: "Beryllium", category: "alkaline-earth", group: 2 },
  [5]:  { symbol: "B", name: "Boron", category: "metalloid", group: 13 },
  [6]:  { symbol: "C", name: "Carbon", category: "nonmetal", group: 14 },
  [7]:  { symbol: "N", name: "Nitrogen", category: "nonmetal", group: 15 },
  [8]:  { symbol: "O", name: "Oxygen", category: "nonmetal", group: 16 },
  [9]:  { symbol: "F", name: "Fluorine", category: "halogen", group: 17 },
  [10]: { symbol: "Ne", name: "Neon", category: "noble", group: 18 },
  
  // Period 3
  [11]: { symbol: "Na", name: "Sodium", category: "alkali", group: 1 },
  [12]: { symbol: "Mg", name: "Magnesium", category: "alkaline-earth", group: 2 },
  [13]: { symbol: "Al", name: "Aluminium", category: "post-transition", group: 13 },
  [14]: { symbol: "Si", name: "Silicon", category: "metalloid", group: 14 },
  [15]: { symbol: "P", name: "Phosphorus", category: "nonmetal", group: 15 },
  [16]: { symbol: "S", name: "Sulfur", category: "nonmetal", group: 16 },
  [17]: { symbol: "Cl", name: "Chlorine", category: "halogen", group: 17 },
  [18]: { symbol: "Ar", name: "Argon", category: "noble", group: 18 },
  
  // Period 4
  [19]: { symbol: "K", name: "Potassium", category: "alkali", group: 1 },
  [20]: { symbol: "Ca", name: "Calcium", category: "alkaline-earth", group: 2 },
  [21]: { symbol: "Sc", name: "Scandium", category: "transition", group: 3 },
  [22]: { symbol: "Ti", name: "Titanium", category: "transition", group: 4 },
  [23]: { symbol: "V", name: "Vanadium", category: "transition", group: 5 },
  [24]: { symbol: "Cr", name: "Chromium", category: "transition", group: 6 },
  [25]: { symbol: "Mn", name: "Manganese", category: "transition", group: 7 },
  [26]: { symbol: "Fe", name: "Iron", category: "transition", group: 8 },
  [27]: { symbol: "Co", name: "Cobalt", category: "transition", group: 9 },
  [28]: { symbol: "Ni", name: "Nickel", category: "transition", group: 10 },
  [29]: { symbol: "Cu", name: "Copper", category: "transition", group: 11 },
  [30]: { symbol: "Zn", name: "Zinc", category: "transition", group: 12 },
  [31]: { symbol: "Ga", name: "Gallium", category: "post-transition", group: 13 },
  [32]: { symbol: "Ge", name: "Germanium", category: "metalloid", group: 14 },
  [33]: { symbol: "As", name: "Arsenic", category: "metalloid", group: 15 },
  [34]: { symbol: "Se", name: "Selenium", category: "nonmetal", group: 16 },
  [35]: { symbol: "Br", name: "Bromine", category: "halogen", group: 17 },
  [36]: { symbol: "Kr", name: "Krypton", category: "noble", group: 18 },
  
  // Period 5
  [37]: { symbol: "Rb", name: "Rubidium", category: "alkali", group: 1 },
  [38]: { symbol: "Sr", name: "Strontium", category: "alkaline-earth", group: 2 },
  [39]: { symbol: "Y", name: "Yttrium", category: "transition", group: 3 },
  [40]: { symbol: "Zr", name: "Zirconium", category: "transition", group: 4 },
  [41]: { symbol: "Nb", name: "Niobium", category: "transition", group: 5 },
  [42]: { symbol: "Mo", name: "Molybdenum", category: "transition", group: 6 },
  [43]: { symbol: "Tc", name: "Technetium", category: "transition", group: 7 },
  [44]: { symbol: "Ru", name: "Ruthenium", category: "transition", group: 8 },
  [45]: { symbol: "Rh", name: "Rhodium", category: "transition", group: 9 },
  [46]: { symbol: "Pd", name: "Palladium", category: "transition", group: 10 },
  [47]: { symbol: "Ag", name: "Silver", category: "transition", group: 11 },
  [48]: { symbol: "Cd", name: "Cadmium", category: "transition", group: 12 },
  [49]: { symbol: "In", name: "Indium", category: "post-transition", group: 13 },
  [50]: { symbol: "Sn", name: "Tin", category: "post-transition", group: 14 },
  [51]: { symbol: "Sb", name: "Antimony", category: "metalloid", group: 15 },
  [52]: { symbol: "Te", name: "Tellurium", category: "metalloid", group: 16 },
  [53]: { symbol: "I", name: "Iodine", category: "halogen", group: 17 },
  [54]: { symbol: "Xe", name: "Xenon", category: "noble", group: 18 },
