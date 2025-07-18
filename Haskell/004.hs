import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))

solution :: Int
solution = maximum palindromes

isPalindrome :: Int -> Bool
isPalindrome n = s == reverse s where s = show n

prods :: [Int]
prods = [n*m | n <- [999,998..100], m <- [999,998..100]]

palindromes :: [Int]
palindromes = [p | p <- prods, isPalindrome p]
