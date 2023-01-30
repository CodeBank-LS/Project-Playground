import { response } from 'express';
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
class filmItemRow extends React.Component{
    render(){
        return(
            <li>
                <a href="#">Some text</a>
            </li>
        )
    }
}

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
        const randNum=Math.round(Math.random()*82)
        const url=`https://swapi.dev/api/people/${randNum}/`
        fetch(url)   
            .then(response => response.json())
            .then(data=>{   
                
                this.setState({
                    name:data.name,
                    height:data.height,
                    homeworld:data.homeworld,
                    films:data.films,
                    loadCharacter:true,
                })
            }) 
               
            
    }

    render(){
        const movies=this.state.films.map((url,i)=>{
            return <filmItemRow key={i}/>
        })
      return(
        <div>
        { 
            this.state.loadCharacter &&
            <div>
          <h1>{this.state.name}</h1>
          <p>{this.state.height} cm</p>
          <p><a href={this.state.homeworld}>homeworld</a></p>
          <ul>
            {
                this.state.films.map(film=>{
                    return <li>{films}</li>
                })
            }
          </ul>
            </div>
        }
          <button type="button" onClick={()=>this.getNewChar()} className="btn">Get a character</button>
    
            
        </div>
      )
    }
  }
export default StarWars;