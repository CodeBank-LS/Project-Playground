
import './App.css';
import Home from './Components/Home';
import Navbar from './Components/Navbar';
import About from './Components/About';
import{ Routes, Route} from 'react-router-dom';
function App() {
  return (
    <div >
    <Navbar />
    <Routes>
    <Route path="/" element={<Home />} />
    <Route path="/about" element={<About />} />
    </Routes>
    
    </div>
  );
}

export default App;
