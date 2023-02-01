import React from "react";


class Item extends React.Component{

    constructor(props){
        super(props)
        this.state={
            clicks:0,
            remains:100

        }
    }

    clickMe(){
        this.setState({
            clicks:this.state.clicks+1,
            remains:this.state.remains-1
        })
    }
    render(){
      return(
        <div>
        <h1 onClick={()=>this.clickMe()}>Hello from {this.props.name}</h1>
        <span>{this.state.clicks} is the number of clicks</span><br></br>
        <span>{this.state.remains} is the remaining of clicks</span>
        </div>
      )
    }
  }

  export default Item; 