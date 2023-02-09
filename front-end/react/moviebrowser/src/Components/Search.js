import Hero from "./Hero";

const Search=({keyword, searchResults})=>{
    const title=`You are searching for ${keyword}`
    console.log(searchResults, "are the searching results")
    return(
        <div>
            <Hero text={title} />
        </div>
    )
}
export default Search;