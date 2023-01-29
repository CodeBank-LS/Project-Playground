import React from 'react';

// class Item extends React.Component{
//     constructor(props){
//         super(props)
//         this.state={
//             clicks:0,
//             totalRemain:100
//         }
//     }
//     clickMe(){
//         this.setState({
//             clicks:this.state.clicks +1,
//             totalRemain:this.state.totalRemain -1,
//         })
//         console.log("I was clicked:",this.props.name)
//     }
//     render(){
//         return(
//             <div>
//                 <h1 onClick={()=>this.clickMe()}>Hello from {this.props.name}</h1>
//                 <span>{this.state.clicks} is the number of clicks</span><br></br>
//                 <span>{this.state.totalRemain} is the left number of clicks</span>
//             </div>
            
//         )
//     }
// }


class StarWars extends React.Component{
    
    constructor(){
        super()
        this.state={
        name:null,
        height:null,
        homeworld:null,
        films:[],
        loadCharacter: false,
        }
    }
    getNewChar(){
        this.setState({
            name:"Luke",
            height:172,
            homeworld:'Tatooine',
            films:['item 1', ' item 2'],
            loadCharacter:true,
        })
    }
    render(){
      return(
        <div>
        { 
            this.state.loadCharacter &&
            <div>
          <h1>{this.state.name}</h1>
          <p>{this.state.height} cm</p>
          <p>Homeworld: {this.state.homeworld}</p>
          <ul>
            <ol>{this.state.films}</ol>
          </ul>
            </div>
        }
          <button type="button" onClick={()=>this.getNewChar()} className="btn">Get a character</button>
    
            
        </div>
      )
    }
  }
export default StarWars;