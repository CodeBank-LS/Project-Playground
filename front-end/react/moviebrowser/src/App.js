
import './App.css';
import Home from './Components/Home';
import Navbar from './Components/Navbar';
import About from './Components/About';
import Search from './Components/Search';

import{ Routes, Route} from 'react-router-dom';
import { useState, useEffect } from 'react';
function App() {

  const[searchResults, setSearchResults]=useState([]);
  const[searchText, setSearchText]=useState('');

  useEffect(()=>{
    console.log(searchText, "is the searched text")
    if(searchText){
    fetch(`https://api.themoviedb.org/3/search/movie?api_key=fcddb16a08023f0e03f430c525d0f232&language=en-US&query=${searchText}&page=1&include_adult=false`)
    .then(response => response.json())
    .then(data=>{
      setSearchResults(data.results)
    })
     }

  },[searchText])
 
  


  return (
    <div >
    <Navbar searchText={searchText} setSearchText={setSearchText} /> 
    <Routes>
      <Route path="/" element={<Home />} />
      <Route path="/about" element={<About />} />
      <Route path='/search' element={<Search keyword={searchText} searchResults={searchResults}/>} />
    </Routes>
    
    </div>
  );
}

export default App;
