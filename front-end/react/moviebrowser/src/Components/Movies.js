import Hero from "./Hero";
import { useParams } from "react-router-dom";
import { useState } from "react";
import { useEffect } from "react";
// import { response } from "express";
const Movie=()=>{
    const {id}=useParams()
    const [movieDetails, setMovieDetails]=useState({})
    const[isLoading, setIsLoading]=useState(true)

    useEffect(()=>{
        console.log('make an api request', id)
        fetch(`https://api.themoviedb.org/3/movie/${id}?api_key=fcddb16a08023f0e03f430c525d0f232&language=en-US`)
            .then(response=>response.json())
            .then(data=>{
                setTimeout(()=>{
                    setMovieDetails(data)
                    setIsLoading(false)
                },2000)
                
            })
    },[id])

    function renderMovieDetails(){
        if(isLoading){
            return <Hero text="Loading ..." />
        }
        if(movieDetails){
            const posterPath=`https://image.tmdb.org/t/p/w500${movieDetails.poster_path}`
            const backdropUrl=`https://image.tmdb.org/t/p/original${movieDetails.backdrop_path}`
            return(
                <div>
               <Hero text={movieDetails.original_title} backdrop={backdropUrl}/> 
               {<div className="container my-5">
                    <div className="row">
                        <div className="col-md-3">
                            <img src={posterPath} alt="..." className="img-fluid shadow rounded" />
                        </div>
                        <div className="col-md-9">
                            <h2>{movieDetails.original_title}</h2>
                            <p className="lead">{movieDetails.overview}</p>
                        </div>
                    </div>
                </div>}
            </div> 
            )
           
            


        }
    }
    return(
        
       renderMovieDetails()
        
    )
};
export default Movie;