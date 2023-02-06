
import './App.css';
import Home from './Components/Home';
import Navbar from './Components/Navbar';
import About from './Components/About';
import Search from './Components/Search';

import{ Routes, Route} from 'react-router-dom';
import { useState } from 'react';
function App() {

  const[searchResults, setsearchResults]=useState([]);
  const[searchText, setSearchText]=useState('');
 
  


  return (
    <div >
    <Navbar />
    <Routes>
    <Route path="/" element={<Home />} />
    <Route path="/about" element={<About />} />
    <Route path='/search'>
      <Search keyword={searchText} searchResults={searchResults} />
    </Route>
    </Routes>
    
    </div>
  );
}

export default App;
