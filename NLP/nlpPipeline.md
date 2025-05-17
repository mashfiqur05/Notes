# Problem
On platforms like Quora, users often ask similar questions using different words. Your task is to think a NLP pipeline for this problem.
------

## 1. Data Acquisition
### a. From where would you acquire the data?

- **Scrapy:** This is a web scraper that can extract data from Quora.
- **public DataSets:** Quora Question Pairs Dataset
- **Octoparse Guide:** provides a detailed guide for scraping Quora data

## 2. Text Preparation
### a. What kind of cleaning steps would you perform?
- Lowercasing
- Removal of stop words
- Removing HTML tags, special character and puntuations
- Correcting misspellings
- Removing URLs and email addresses

### b. What text preprocessing step would you apply?
- Tokenization 
- Lemmatization
- Vectorization 


## 3. Feature Engineering
### a.What kind of features would you create?
- **Word overlap:** % of common words
- Parts of speech tags
- Sentiment scores
- Text length, average word length

## 4. Modelling
### a. What algorithm would you use to solve the problem at hand?
Use engineered features to train:
- Logistic Regression
- Random Forest
- Gradient Boosting (e.g., XGBoost)

### b. What intrinsic evaluation metrics would you use?
- Accuracy
- Precision
- Recall
- F1-score
- ROC AUC


## c. What extrinsic evaluation metrics would you use?
- Reduction in duplicate questions
- Improved user satisfaction
- Speed of response via duplicate detection

## 5. Deployment
### a. How would you deploy your solution into the entire product?
- Convert model to API 
- Integrate with Quora’s question submission form to flag potential duplicates

### b. How and what things will you monitor?
- False positive/negative rates
- Feedback from users

### c. What would be your model update strategy?
- Retrain with new data periodically
- Use feedback loop to label more data
