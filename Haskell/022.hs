import Data.Time
import System.IO
import Data.List


main :: IO ()
main = do 
  !startTime <- getCurrentTime
  !result <- solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))
  --putStrLn $ (reverse.tail.reverse) (show diffTime)


solution :: IO Int
solution = do 
    file <- openFile "0022_names.txt" ReadMode
    input <- hGetContents file
    let names = sort $ map (filter (\x -> x /= '[' && x /= '\"' && x /= ']')) (splitOn ','  input)
    return $ sum $ alphaScore 1 names


alphaValue :: String -> Int
alphaValue s = sum $ map (\x -> fromEnum x - fromEnum 'A' + 1) s 

alphaScore :: Int -> [String] -> [Int]
alphaScore k []     = []
alphaScore k (x:xs) = k * alphaValue x : alphaScore (k+1) xs

split :: Char -> String -> [String] -> String -> [String]
split c partial res []     = partial:res
split c partial res (x:xs) = if c == x then split c "" (partial:res) xs else split c (partial++[x]) res xs

splitOn :: Char -> String -> [String]
splitOn c xs = reverse $ split c "" [] xs 
