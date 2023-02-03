import './App.css';
import Navbar from './Components/Navbar';
import Home from './Components/Home';
import About from './Components/About';
import { Routes, Route } from 'react-router-dom';



function App() {
  return (
    <div>
      <Navbar />
      <Routes>
      <Route path="/" element={<Home />}></Route>
      <Route path="/about" element={<About />}></Route>
      </Routes>
      
    </div>
  );
}

export default App;
