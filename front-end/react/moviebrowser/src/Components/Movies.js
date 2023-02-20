import Hero from "./Hero";
import { useParams } from "react-router-dom";
import { useState } from "react";
import { useEffect } from "react";
// import { response } from "express";
const Movie=()=>{
    const {id}=useParams()
    console.log(id)

    const [movieDetails, setMovieDetails]=useState({})

    useEffect(()=>{
        console.log('make an api request', id)
        fetch(`https://api.themoviedb.org/3/movie/${id}?api_key=<<api_key>>&language=en-US`)
            .then(response=>response.json())
            .then(data=>{
                setMovieDetails(data)
            })
    },[id])
    return(
        <div>
        <Hero text={movieDetails.original_title}/>
       
        </div>
        
    )
}
export default Movie;