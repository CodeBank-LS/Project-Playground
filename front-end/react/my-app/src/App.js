// import { response } from 'express';
import React from 'react';
// import logo from './logo.svg';
import './App.css';
// import Item from './myItems';
class FilmRow extends React.Component{
  render(){
    return(
      <li>
        <a href={this.props.url}>{this.props.url}</a>
      </li>
    )
  }
}
class StarWars extends React.Component{
  constructor(props){
    super(props)
    this.state={
      loadCha:false,
      name:null,
      height:null,
      homeworld:null,
      films:[],
    }
  }
  getCha(){
    console.log("get new character from button click")
    const randNum=Math.round(Math.random()*82)
    const url=`https://swapi.dev/api/people/${randNum}/`
    fetch(url)
      .then(response=>response.json())
      .then(data=>{
    this.setState({
      name:data.name,
      height: data.height,
      homeworld:data.homeworld,
      films:data.films,
      loadCha:true,
    })
   })
    
  }
  
  render(){
    const movies=this.state.films.map((url, i)=>{
      return <FilmRow key={i} url={url} />
    })

    return(
     <div>
      {
        this.state.loadCha&&
        <div>
          <h1>{this.state.name}</h1>
          <p>{this.state.height} cm</p>
          <p><a href={this.state.homeworld}>Homeworld</a></p>
          <ul>
            {movies}
          </ul>
        </div>
      }
     
      <button type="button" 
      onClick={()=>this.getCha()}
      className="btn">Generate Character</button>

     </div>
    )
  }
}



function App() {
  return (
    <div className="App">
      <header className="App-header">
        {/* <img src={logo} className="App-logo" alt="logo" /> */}
       <StarWars />
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
