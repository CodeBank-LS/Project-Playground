import { Link } from "react-router-dom";
import Hero from "./Hero";

//TMDB API key= fcddb16a08023f0e03f430c525d0f232

// https://api.themoviedb.org/3/search/movie?api_key=fcddb16a08023f0e03f430c525d0f232&language=en-US&query=star&page=1&include_adult=false

const MovieCard=({movie})=>{
    const posterUrl=`https://image.tmdb.org/t/p/w500${movie.poster_path}`
    const detailUrl=`/movies/${movie.id}`
    return (
        <div className="col-lg-3 col-md-2 co-3 my-4">
            <div className="card">
            <img src={posterUrl} className="card-img-top" alt={movie.original_title} />
                <div className="card-body">
                    <h5 className="card-title">{movie.original_title}</h5>
                   
                    <Link to={detailUrl} className="btn btn-primary">Show details</Link>
                </div>
            </div>
        </div>
    );
};

const Search=({keyword, searchResults})=>{
    const title=`You are searching for ${keyword}`

    //loop each result in map function
    const resultHtml=searchResults&&searchResults.map((obj,i)=>{
        return <MovieCard movie={obj} key={i} />

    })
    return(
        <div>
            <Hero text={title} />
            {resultHtml &&
                <div className="container">
                    <div className="row">
                        {resultHtml}
                    </div>
                </div>
        }
        </div>
    );
};
export default Search;